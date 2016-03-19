/*
Copyright (c) 2013-14 Microsoft Corporation. All rights reserved.
Released under Apache 2.0 license as described in the file LICENSE.

Author: Leonardo de Moura
*/
#pragma once
#include <memory>
#include <utility>
#include <algorithm>
#include "util/flet.h"
#include "util/name_set.h"
#include "util/fresh_name.h"
#include "kernel/environment.h"
#include "kernel/converter.h"
#include "kernel/expr_maps.h"
#include "kernel/abstract_type_context.h"

namespace lean {
/** \brief Lean Type Checker. It can also be used to infer types, check whether a
    type \c A is convertible to a type \c B, etc. */
class type_checker : public abstract_type_context {
    /* In the type checker cache, we must take into account binder information.
       Examples:
       The type of (lambda x : A, t)   is (Pi x : A, typeof(t))
       The type of (lambda {x : A}, t) is (Pi {x : A}, typeof(t)) */
    typedef expr_bi_struct_map<expr> cache;
    environment                m_env;
    std::unique_ptr<converter> m_conv;
    cache                      m_infer_type_cache[2];
    bool                       m_memoize;
    level_param_names const *  m_params;

    friend class converter; // allow converter to access the following methods
    pair<expr, expr> open_binding_body(expr const & e);
    expr ensure_sort_core(expr e, expr const & s);
    expr ensure_pi_core(expr e, expr const & s);
    void check_level(level const & l, expr const & s);
    expr infer_constant(expr const & e, bool infer_only);
    expr infer_macro(expr const & e, bool infer_only);
    expr infer_lambda(expr const & e, bool infer_only);
    expr infer_pi(expr const & e, bool infer_only);
    expr infer_app(expr const & e, bool infer_only);
    expr infer_let(expr const & e, bool infer_only);
    expr infer_type_core(expr const & e, bool infer_only);
    expr infer_type(expr const & e);
public:
    /** \brief Create a type checker for the given environment. The auxiliary names created by this
       type checker are based on the given name generator.

       memoize: if true, then inferred types are memoized/cached */
    type_checker(environment const & env, std::unique_ptr<converter> && conv, bool memoize = true);
    type_checker(environment const & env, bool memoize = true);
    ~type_checker();

    virtual environment const & env() const { return m_env; }

    /** \brief Return the type of \c t.
        It does not check whether the input expression is type correct or not.
        The contract is: IF the input expression is type correct, then the inferred
        type is correct.
        Throw an exception if a type error is found. */
    virtual expr infer(expr const & t) { return infer_type(t); }

    /** \brief Type check the given expression, and return the type of \c t.
        Throw an exception if a type error is found.  */
    virtual expr check(expr const & t, level_param_names const & ps = level_param_names());
    /** \brief Like \c check, but ignores undefined universes */
    expr check_ignore_undefined_universes(expr const & e);

    /** \brief Return true iff t is definitionally equal to s. */
    virtual bool is_def_eq(expr const & t, expr const & s);
    /** \brief Return true iff types of \c t and \c s are (may be) definitionally equal. */
    bool is_def_eq_types(expr const & t, expr const & s);
    /** \brief Return true iff t is a proposition. */
    bool is_prop(expr const & t);
    /** \brief Return the weak head normal form of \c t. */
    virtual expr whnf(expr const & t);
    /** \brief Return a Pi if \c t is convertible to a Pi type. Throw an exception otherwise.
        The argument \c s is used when reporting errors */
    expr ensure_pi(expr const & t, expr const & s);
    expr ensure_pi(expr const & t) { return ensure_pi(t, t); }
    /** \brief Mare sure type of \c e is a Pi, and return it. Throw an exception otherwise. */
    expr ensure_fun(expr const & e) {
        return ensure_pi(infer(e), e);
    }
    /** \brief Return a Sort if \c t is convertible to Sort. Throw an exception otherwise.
        The argument \c s is used when reporting errors. */
    expr ensure_sort(expr const & t, expr const & s);
    /** \brief Return a Sort if \c t is convertible to Sort. Throw an exception otherwise. */
    expr ensure_sort(expr const & t) { return ensure_sort(t, t); }
    /** \brief Mare sure type of \c e is a sort, and return it. Throw an exception otherwise. */
    expr ensure_type(expr const & e) {
        return ensure_sort(infer(e), e);
    }

    optional<expr> expand_macro(expr const & m);

    /** \brief Return true iff \c d is opaque with respect to this type checker. */
    bool is_opaque(declaration const & d) const;
    /** \brief Return true iff the constant \c c is opaque with respect to this type checker. */
    bool is_opaque(expr const & c) const;

    /** \brief Return a metavariable that may be stucking the \c e's reduction. */
    virtual optional<expr> is_stuck(expr const & e);

    optional<declaration> is_delta(expr const & e) const { return m_conv->is_delta(e); }

    bool may_reduce_later(expr const & e) { return !is_meta(e) && static_cast<bool>(m_conv->is_stuck(e, *this)); }

    template<typename F>
    typename std::result_of<F()>::type with_params(level_param_names const & ps, F && f) {
        flet<level_param_names const *> updt(m_params, &ps);
        return f();
    }
};

typedef std::shared_ptr<type_checker> type_checker_ref;

void check_no_metavar(environment const & env, name const & n, expr const & e, bool is_type);

/** \brief Type check the given declaration, and return a certified declaration if it is type correct.
    Throw an exception if the declaration is type incorrect. */
certified_declaration check(environment const & env, declaration const & d);
certified_declaration check(environment const & env, declaration const & d, name_predicate const & opaque_hints);

void initialize_type_checker();
void finalize_type_checker();
}
