/* ARC definitions for signal handling calling conventions.
   Copyright (C) 2017 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */

#include <sys/ucontext.h>
#include "kernel-features.h"

#define SIGCONTEXT int _code, struct ucontext_t *
#define SIGCONTEXT_EXTRA_ARGS _code,
#define GET_PC(ctx)    ((void *) (ctx)->uc_mcontext.scratch.ret)
#define GET_FRAME(ctx) ((void *) (ctx)->uc_mcontext.scratch.fp)
#define GET_STACK(ctx) ((void *) (ctx)->uc_mcontext.scratch.sp)
#define CALL_SIGHANDLER(handler, signo, ctx) \
  (handler)((signo), SIGCONTEXT_EXTRA_ARGS (ctx))
