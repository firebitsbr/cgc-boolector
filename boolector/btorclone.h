/*  Boolector: Satisfiablity Modulo Theories (SMT) solver.
 *
 *  Copyright (C) 2013-2015 Aina Niemetz.
 *  Copyright (C) 2015 Mathias Preiner.
 *
 *  All rights reserved.
 *
 *  This file is part of Boolector.
 *  See COPYING for more information on using this software.
 */
#ifndef BTORCLONE_H_INCLUDED
#define BTORCLONE_H_INCLUDED

#include "utils/btormap.h"

/* Clone an existing boolector instance. */
Btor *btor_clone_btor (Btor * btor);

/* Clone the expression layer of an existing boolector instance. */
Btor *btor_clone_exp_layer (Btor * btor, BtorNodeMap ** exp_map);

/* Rebuild 'exp' (and all expressions below) of an existing boolector instance
 * 'btor' in an existing boolector instance 'clone' with rewrite level
 * 'rewrite_level'. 'exp_map' must contain all previously cloned expressions.
 */
BtorNode *btor_recursively_rebuild_exp_clone (Btor * btor, 
                                              Btor * clone, 
                                              BtorNode * exp, 
                                              BtorNodeMap * exp_map,
                                              int rewrite_level);

/* helpers for hash table cloning */
void * btor_clone_key_as_node (BtorMemMgr * mm,
                               const void * map,
                               const void * key);

void * btor_clone_key_as_str  (BtorMemMgr * mm,
                               const void * map,
                               const void * key);

void * btor_clone_key_as_bv_tuple (BtorMemMgr * mm,
                                   const void * map,
                                   const void * t);

void btor_clone_data_as_node_ptr (BtorMemMgr *mm,
                                  const void * map,
                                  BtorPtrHashData * data,
                                  BtorPtrHashData * cloned_data);

void btor_clone_data_as_str_ptr  (BtorMemMgr *mm,
                                  const void * str_table,
                                  BtorPtrHashData * data,
                                  BtorPtrHashData * cloned_data);

void btor_clone_data_as_int (BtorMemMgr *mm,
                             const void * map,
                             BtorPtrHashData * data, 
                             BtorPtrHashData * cloned_data);

void btor_clone_data_as_bv_ptr (BtorMemMgr *mm,
                                const void * map,
                                BtorPtrHashData * data,
                                BtorPtrHashData * cloned_data);

void btor_clone_data_as_bv_htable_ptr (BtorMemMgr *mm,
                                       const void * map,
                                       BtorPtrHashData * data, 
                                       BtorPtrHashData * cloned_data);

void btor_clone_data_as_htable_ptr (BtorMemMgr *mm,
                                    const void * map,
                                    BtorPtrHashData * data, 
                                    BtorPtrHashData * cloned_data);

void btor_clone_node_ptr_stack (BtorMemMgr * mm,
                                       BtorNodePtrStack * stack,
                                BtorNodePtrStack * res,
                                      BtorNodeMap * exp_map);
#endif
