/*
* Copyright 2018-2019 Redis Labs Ltd. and Contributors
*
* This file is available under the Redis Labs Source Available License Agreement
*/

#ifndef __OP_MERGE_H
#define __OP_MERGE_H

#include "op.h"
#include "../../graph/entities/node.h"
#include "../../graph/entities/edge.h"
#include "../../parser/ast_shared.h"
#include "../../resultset/resultset.h"

/* Merge execution plan operation,
 * this operation will create a pattern P if it doesn't not exists
 * in the graph, the pattern must be either fully matched, in which case
 * we'll simply return, otherwise (no match/ partial match) the ENTIRE pattern
 * is created. */

typedef struct {
    OpBase op;                        // Base op.
    GraphContext *gc;                 // Graph data.
    NodeCreateCtx *nodes_to_merge;
    EdgeCreateCtx *edges_to_merge;
    ResultSet *result_set;            // Required for statistics updates.
    uint record_len;
    bool matched;                     // Has the entire pattern been matched?
    bool created;                     // Has the entire pattern been created?
} OpMerge;

OpBase* NewMergeOp(ResultSet *result_set, NodeCreateCtx *nodes_to_merge, EdgeCreateCtx *edges_to_merge, uint record_len);
Record OpMergeConsume(OpBase *opBase);
OpResult OpMergeReset(OpBase *ctx);
void OpMergeFree(OpBase *ctx);

#endif
