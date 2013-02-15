/*
   Copyright (C) Cfengine AS

   This file is part of Cfengine 3 - written and maintained by Cfengine AS.

   This program is free software; you can redistribute it and/or modify it
   under the terms of the GNU General Public License as published by the
   Free Software Foundation; version 3.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program; if not, write to the Free Software
  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA

  To the extent this program is licensed as part of the Enterprise
  versions of Cfengine, the applicable Commerical Open Source License
  (COSL) may apply to this file if you as a licensee so wish it. See
  included file COSL.txt.
*/

#ifndef CFENGINE_FNCALL_H
#define CFENGINE_FNCALL_H

#include "cf3.defs.h"

struct FnCall_
{
    char *name;
    Rlist *args;
    char *ns;
};

int IsBuiltinFnCall(Rval rval);
FnCall *NewFnCall(const char *name, Rlist *args);
FnCall *CopyFnCall(const FnCall *f);
void DeleteFnCall(FnCall *fp);
void ShowFnCall(FILE *fout, const FnCall *fp);
FnCallResult EvaluateFunctionCall(FnCall *fp, const Promise *pp);
DataType FunctionReturnType(const char *name);
const FnCallType *FindFunction(const char *name);

#endif
