/*
Copyright (c) 2016 Microsoft Corporation. All rights reserved.
Released under Apache 2.0 license as described in the file LICENSE.

Author: Leonardo de Moura
*/
#include "library/tactic/kabstract.h"
#include "library/tactic/tactic_state.h"
#include "library/tactic/intro_tactic.h"
#include "library/tactic/revert_tactic.h"
#include "library/tactic/clear_tactic.h"
#include "library/tactic/app_builder_tactics.h"
#include "library/tactic/subst_tactic.h"
#include "library/tactic/exact_tactic.h"
#include "library/tactic/change_tactic.h"
#include "library/tactic/assert_tactic.h"
#include "library/tactic/fun_info_tactics.h"
#include "library/tactic/induction_tactic.h"
#include "library/tactic/cases_tactic.h"
#include "library/tactic/generalize_tactic.h"
#include "library/tactic/elaborate.h"
#include "library/tactic/eval.h"
#include "library/tactic/destruct_tactic.h"

namespace lean {
void initialize_tactic_module() {
    initialize_kabstract();
    initialize_tactic_state();
    initialize_intro_tactic();
    initialize_revert_tactic();
    initialize_clear_tactic();
    initialize_app_builder_tactics();
    initialize_subst_tactic();
    initialize_exact_tactic();
    initialize_change_tactic();
    initialize_assert_tactic();
    initialize_fun_info_tactics();
    initialize_induction_tactic();
    initialize_cases_tactic();
    initialize_generalize_tactic();
    initialize_elaborate();
    initialize_eval();
    initialize_destruct_tactic();
}
void finalize_tactic_module() {
    finalize_destruct_tactic();
    finalize_eval();
    finalize_elaborate();
    finalize_generalize_tactic();
    finalize_cases_tactic();
    finalize_induction_tactic();
    finalize_fun_info_tactics();
    finalize_assert_tactic();
    finalize_change_tactic();
    finalize_exact_tactic();
    finalize_subst_tactic();
    finalize_app_builder_tactics();
    finalize_clear_tactic();
    finalize_revert_tactic();
    finalize_intro_tactic();
    finalize_tactic_state();
    finalize_kabstract();
}
}
