# NOTE: this is a GNU Makefile.  You must use "gmake" rather than "make".
#
# Makefile for the virtual memory assignment
#    Defines set up assuming the virtual memory assignment is done before 
# 	the file system assignment. If not, use the "filesys first"  
#	defines below. 
#
# Also, if you want to simplify the translation so it assumes
# only linear page tables, don't define USE_TLB.
#
# Copyright (c) 1992 The Regents of the University of California.
# All rights reserved.  See copyright.h for copyright notice and limitation 
# of liability and disclaimer of warranty provisions.

DEFINES = -DUSER_PROGRAM  -DFILESYS_NEEDED -DFILESYS_STUB -DVM -DUSE_TLB
INCPATH = -I../filesys -I../bin -I../vm -I../userprog -I../threads -I../machine
HFILES = $(THREAD_H) $(USERPROG_H) $(VM_H)
CFILES = $(THREAD_C) $(USERPROG_C) $(VM_C)
C_OFILES = $(THREAD_O) $(USERPROG_O) $(VM_O)

# if file sys done first!
# DEFINES = -DUSER_PROGRAM -DFILESYS_NEEDED -DFILESYS -DVM -DUSE_TLB
# INCPATH = -I../vm -I../bin -I../filesys -I../userprog -I../threads -I../machine
# HFILES = $(THREAD_H) $(USERPROG_H) $(FILESYS_H) $(VM_H)
# CFILES = $(THREAD_C) $(USERPROG_C) $(FILESYS_C) $(VM_C)
# C_OFILES = $(THREAD_O) $(USERPROG_O) $(FILESYS_O) $(VM_O)

include ../Makefile.common
include ../Makefile.dep
#-----------------------------------------------------------------
# DO NOT DELETE THIS LINE -- make depend uses it
# DEPENDENCIES MUST END AT END OF FILE
main.o: ../threads/main.cc /usr/include/stdc-predef.h \
 ../threads/copyright.h ../threads/utility.h /usr/include/stdlib.h \
 /usr/include/features.h /usr/include/sys/cdefs.h \
 /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h \
 /usr/include/gnu/stubs-32.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/stddef.h \
 /usr/include/bits/waitflags.h /usr/include/bits/waitstatus.h \
 /usr/include/endian.h /usr/include/bits/endian.h \
 /usr/include/bits/byteswap.h /usr/include/bits/types.h \
 /usr/include/bits/typesizes.h /usr/include/bits/byteswap-16.h \
 /usr/include/xlocale.h /usr/include/sys/types.h /usr/include/time.h \
 /usr/include/sys/select.h /usr/include/bits/select.h \
 /usr/include/bits/sigset.h /usr/include/bits/time.h \
 /usr/include/sys/sysmacros.h /usr/include/bits/pthreadtypes.h \
 /usr/include/alloca.h /usr/include/bits/stdlib-float.h \
 ../machine/sysdep.h ../threads/copyright.h /usr/include/stdio.h \
 /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/stdarg.h \
 /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h \
 /usr/include/string.h ../threads/system.h ../threads/thread.h \
 ../machine/machine.h ../threads/utility.h ../machine/translate.h \
 ../machine/disk.h ../userprog/addrspace.h ../filesys/filesys.h \
 ../filesys/openfile.h ../threads/scheduler.h ../threads/list.h \
 ../machine/interrupt.h ../threads/list.h ../machine/stats.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/vector \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/stl_algobase.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/x86_64-pc-linux-gnu/32/bits/c++config.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/x86_64-pc-linux-gnu/32/bits/os_defines.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/x86_64-pc-linux-gnu/32/bits/cpu_defines.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/functexcept.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/exception_defines.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/cpp_type_traits.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/ext/type_traits.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/ext/numeric_traits.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/stl_pair.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/move.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/concept_check.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/stl_iterator_base_types.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/stl_iterator_base_funcs.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/debug/debug.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/stl_iterator.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/ptr_traits.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/predefined_ops.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/allocator.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/x86_64-pc-linux-gnu/32/bits/c++allocator.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/ext/new_allocator.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/new \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/exception \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/atomic_lockfree_defines.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/memoryfwd.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/stl_construct.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/ext/alloc_traits.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/stl_uninitialized.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/stl_vector.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/stl_bvector.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/range_access.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/vector.tcc \
 ../machine/timer.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/fstream \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/istream \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/ios \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/iosfwd \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/stringfwd.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/postypes.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/cwchar \
 /usr/include/bits/wchar.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/char_traits.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/localefwd.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/x86_64-pc-linux-gnu/32/bits/c++locale.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/clocale \
 /usr/include/locale.h /usr/include/bits/locale.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/cctype \
 /usr/include/ctype.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/ios_base.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/ext/atomicity.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/x86_64-pc-linux-gnu/32/bits/gthr.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/x86_64-pc-linux-gnu/32/bits/gthr-default.h \
 /usr/include/pthread.h /usr/include/sched.h /usr/include/bits/sched.h \
 /usr/include/bits/timex.h /usr/include/bits/setjmp.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/x86_64-pc-linux-gnu/32/bits/atomic_word.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/locale_classes.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/string \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/ostream_insert.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/cxxabi_forced.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/stl_function.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/backward/binders.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/basic_string.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/basic_string.tcc \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/locale_classes.tcc \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/streambuf \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/streambuf.tcc \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/basic_ios.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/locale_facets.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/cwctype \
 /usr/include/wctype.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/x86_64-pc-linux-gnu/32/bits/ctype_base.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/streambuf_iterator.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/x86_64-pc-linux-gnu/32/bits/ctype_inline.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/locale_facets.tcc \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/basic_ios.tcc \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/ostream \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/ostream.tcc \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/istream.tcc \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/codecvt.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/cstdio \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/x86_64-pc-linux-gnu/32/bits/basic_file.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/x86_64-pc-linux-gnu/32/bits/c++io.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/fstream.tcc
list.o: ../threads/list.cc /usr/include/stdc-predef.h \
 ../threads/copyright.h ../threads/list.h ../threads/utility.h \
 /usr/include/stdlib.h /usr/include/features.h /usr/include/sys/cdefs.h \
 /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h \
 /usr/include/gnu/stubs-32.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/stddef.h \
 /usr/include/bits/waitflags.h /usr/include/bits/waitstatus.h \
 /usr/include/endian.h /usr/include/bits/endian.h \
 /usr/include/bits/byteswap.h /usr/include/bits/types.h \
 /usr/include/bits/typesizes.h /usr/include/bits/byteswap-16.h \
 /usr/include/xlocale.h /usr/include/sys/types.h /usr/include/time.h \
 /usr/include/sys/select.h /usr/include/bits/select.h \
 /usr/include/bits/sigset.h /usr/include/bits/time.h \
 /usr/include/sys/sysmacros.h /usr/include/bits/pthreadtypes.h \
 /usr/include/alloca.h /usr/include/bits/stdlib-float.h \
 ../machine/sysdep.h ../threads/copyright.h /usr/include/stdio.h \
 /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/stdarg.h \
 /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h \
 /usr/include/string.h
scheduler.o: ../threads/scheduler.cc /usr/include/stdc-predef.h \
 ../threads/copyright.h ../threads/scheduler.h ../threads/list.h \
 ../threads/utility.h /usr/include/stdlib.h /usr/include/features.h \
 /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h \
 /usr/include/gnu/stubs.h /usr/include/gnu/stubs-32.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/stddef.h \
 /usr/include/bits/waitflags.h /usr/include/bits/waitstatus.h \
 /usr/include/endian.h /usr/include/bits/endian.h \
 /usr/include/bits/byteswap.h /usr/include/bits/types.h \
 /usr/include/bits/typesizes.h /usr/include/bits/byteswap-16.h \
 /usr/include/xlocale.h /usr/include/sys/types.h /usr/include/time.h \
 /usr/include/sys/select.h /usr/include/bits/select.h \
 /usr/include/bits/sigset.h /usr/include/bits/time.h \
 /usr/include/sys/sysmacros.h /usr/include/bits/pthreadtypes.h \
 /usr/include/alloca.h /usr/include/bits/stdlib-float.h \
 ../machine/sysdep.h ../threads/copyright.h /usr/include/stdio.h \
 /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/stdarg.h \
 /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h \
 /usr/include/string.h ../threads/thread.h ../machine/machine.h \
 ../threads/utility.h ../machine/translate.h ../machine/disk.h \
 ../userprog/addrspace.h ../filesys/filesys.h ../filesys/openfile.h \
 ../threads/system.h ../machine/interrupt.h ../threads/list.h \
 ../machine/stats.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/vector \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/stl_algobase.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/x86_64-pc-linux-gnu/32/bits/c++config.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/x86_64-pc-linux-gnu/32/bits/os_defines.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/x86_64-pc-linux-gnu/32/bits/cpu_defines.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/functexcept.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/exception_defines.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/cpp_type_traits.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/ext/type_traits.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/ext/numeric_traits.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/stl_pair.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/move.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/concept_check.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/stl_iterator_base_types.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/stl_iterator_base_funcs.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/debug/debug.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/stl_iterator.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/ptr_traits.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/predefined_ops.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/allocator.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/x86_64-pc-linux-gnu/32/bits/c++allocator.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/ext/new_allocator.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/new \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/exception \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/atomic_lockfree_defines.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/memoryfwd.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/stl_construct.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/ext/alloc_traits.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/stl_uninitialized.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/stl_vector.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/stl_bvector.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/range_access.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/vector.tcc \
 ../machine/timer.h
synch.o: ../threads/synch.cc /usr/include/stdc-predef.h \
 ../threads/copyright.h ../threads/synch.h ../threads/thread.h \
 ../threads/utility.h /usr/include/stdlib.h /usr/include/features.h \
 /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h \
 /usr/include/gnu/stubs.h /usr/include/gnu/stubs-32.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/stddef.h \
 /usr/include/bits/waitflags.h /usr/include/bits/waitstatus.h \
 /usr/include/endian.h /usr/include/bits/endian.h \
 /usr/include/bits/byteswap.h /usr/include/bits/types.h \
 /usr/include/bits/typesizes.h /usr/include/bits/byteswap-16.h \
 /usr/include/xlocale.h /usr/include/sys/types.h /usr/include/time.h \
 /usr/include/sys/select.h /usr/include/bits/select.h \
 /usr/include/bits/sigset.h /usr/include/bits/time.h \
 /usr/include/sys/sysmacros.h /usr/include/bits/pthreadtypes.h \
 /usr/include/alloca.h /usr/include/bits/stdlib-float.h \
 ../machine/sysdep.h ../threads/copyright.h /usr/include/stdio.h \
 /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/stdarg.h \
 /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h \
 /usr/include/string.h ../machine/machine.h ../threads/utility.h \
 ../machine/translate.h ../machine/disk.h ../userprog/addrspace.h \
 ../filesys/filesys.h ../filesys/openfile.h ../threads/list.h \
 ../threads/system.h ../threads/scheduler.h ../machine/interrupt.h \
 ../threads/list.h ../machine/stats.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/vector \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/stl_algobase.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/x86_64-pc-linux-gnu/32/bits/c++config.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/x86_64-pc-linux-gnu/32/bits/os_defines.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/x86_64-pc-linux-gnu/32/bits/cpu_defines.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/functexcept.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/exception_defines.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/cpp_type_traits.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/ext/type_traits.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/ext/numeric_traits.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/stl_pair.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/move.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/concept_check.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/stl_iterator_base_types.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/stl_iterator_base_funcs.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/debug/debug.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/stl_iterator.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/ptr_traits.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/predefined_ops.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/allocator.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/x86_64-pc-linux-gnu/32/bits/c++allocator.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/ext/new_allocator.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/new \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/exception \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/atomic_lockfree_defines.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/memoryfwd.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/stl_construct.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/ext/alloc_traits.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/stl_uninitialized.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/stl_vector.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/stl_bvector.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/range_access.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/vector.tcc \
 ../machine/timer.h
synchlist.o: ../threads/synchlist.cc /usr/include/stdc-predef.h \
 ../threads/copyright.h ../threads/synchlist.h ../threads/list.h \
 ../threads/utility.h /usr/include/stdlib.h /usr/include/features.h \
 /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h \
 /usr/include/gnu/stubs.h /usr/include/gnu/stubs-32.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/stddef.h \
 /usr/include/bits/waitflags.h /usr/include/bits/waitstatus.h \
 /usr/include/endian.h /usr/include/bits/endian.h \
 /usr/include/bits/byteswap.h /usr/include/bits/types.h \
 /usr/include/bits/typesizes.h /usr/include/bits/byteswap-16.h \
 /usr/include/xlocale.h /usr/include/sys/types.h /usr/include/time.h \
 /usr/include/sys/select.h /usr/include/bits/select.h \
 /usr/include/bits/sigset.h /usr/include/bits/time.h \
 /usr/include/sys/sysmacros.h /usr/include/bits/pthreadtypes.h \
 /usr/include/alloca.h /usr/include/bits/stdlib-float.h \
 ../machine/sysdep.h ../threads/copyright.h /usr/include/stdio.h \
 /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/stdarg.h \
 /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h \
 /usr/include/string.h ../threads/synch.h ../threads/thread.h \
 ../machine/machine.h ../threads/utility.h ../machine/translate.h \
 ../machine/disk.h ../userprog/addrspace.h ../filesys/filesys.h \
 ../filesys/openfile.h
system.o: ../threads/system.cc /usr/include/stdc-predef.h \
 ../threads/copyright.h ../threads/system.h ../threads/utility.h \
 /usr/include/stdlib.h /usr/include/features.h /usr/include/sys/cdefs.h \
 /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h \
 /usr/include/gnu/stubs-32.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/stddef.h \
 /usr/include/bits/waitflags.h /usr/include/bits/waitstatus.h \
 /usr/include/endian.h /usr/include/bits/endian.h \
 /usr/include/bits/byteswap.h /usr/include/bits/types.h \
 /usr/include/bits/typesizes.h /usr/include/bits/byteswap-16.h \
 /usr/include/xlocale.h /usr/include/sys/types.h /usr/include/time.h \
 /usr/include/sys/select.h /usr/include/bits/select.h \
 /usr/include/bits/sigset.h /usr/include/bits/time.h \
 /usr/include/sys/sysmacros.h /usr/include/bits/pthreadtypes.h \
 /usr/include/alloca.h /usr/include/bits/stdlib-float.h \
 ../machine/sysdep.h ../threads/copyright.h /usr/include/stdio.h \
 /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/stdarg.h \
 /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h \
 /usr/include/string.h ../threads/thread.h ../machine/machine.h \
 ../threads/utility.h ../machine/translate.h ../machine/disk.h \
 ../userprog/addrspace.h ../filesys/filesys.h ../filesys/openfile.h \
 ../threads/scheduler.h ../threads/list.h ../machine/interrupt.h \
 ../threads/list.h ../machine/stats.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/vector \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/stl_algobase.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/x86_64-pc-linux-gnu/32/bits/c++config.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/x86_64-pc-linux-gnu/32/bits/os_defines.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/x86_64-pc-linux-gnu/32/bits/cpu_defines.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/functexcept.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/exception_defines.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/cpp_type_traits.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/ext/type_traits.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/ext/numeric_traits.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/stl_pair.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/move.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/concept_check.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/stl_iterator_base_types.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/stl_iterator_base_funcs.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/debug/debug.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/stl_iterator.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/ptr_traits.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/predefined_ops.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/allocator.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/x86_64-pc-linux-gnu/32/bits/c++allocator.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/ext/new_allocator.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/new \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/exception \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/atomic_lockfree_defines.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/memoryfwd.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/stl_construct.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/ext/alloc_traits.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/stl_uninitialized.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/stl_vector.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/stl_bvector.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/range_access.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/vector.tcc \
 ../machine/timer.h
thread.o: ../threads/thread.cc /usr/include/stdc-predef.h \
 ../threads/copyright.h ../threads/thread.h ../threads/utility.h \
 /usr/include/stdlib.h /usr/include/features.h /usr/include/sys/cdefs.h \
 /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h \
 /usr/include/gnu/stubs-32.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/stddef.h \
 /usr/include/bits/waitflags.h /usr/include/bits/waitstatus.h \
 /usr/include/endian.h /usr/include/bits/endian.h \
 /usr/include/bits/byteswap.h /usr/include/bits/types.h \
 /usr/include/bits/typesizes.h /usr/include/bits/byteswap-16.h \
 /usr/include/xlocale.h /usr/include/sys/types.h /usr/include/time.h \
 /usr/include/sys/select.h /usr/include/bits/select.h \
 /usr/include/bits/sigset.h /usr/include/bits/time.h \
 /usr/include/sys/sysmacros.h /usr/include/bits/pthreadtypes.h \
 /usr/include/alloca.h /usr/include/bits/stdlib-float.h \
 ../machine/sysdep.h ../threads/copyright.h /usr/include/stdio.h \
 /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/stdarg.h \
 /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h \
 /usr/include/string.h ../machine/machine.h ../threads/utility.h \
 ../machine/translate.h ../machine/disk.h ../userprog/addrspace.h \
 ../filesys/filesys.h ../filesys/openfile.h ../threads/switch.h \
 ../threads/synch.h ../threads/list.h ../threads/system.h \
 ../threads/scheduler.h ../machine/interrupt.h ../threads/list.h \
 ../machine/stats.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/vector \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/stl_algobase.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/x86_64-pc-linux-gnu/32/bits/c++config.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/x86_64-pc-linux-gnu/32/bits/os_defines.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/x86_64-pc-linux-gnu/32/bits/cpu_defines.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/functexcept.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/exception_defines.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/cpp_type_traits.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/ext/type_traits.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/ext/numeric_traits.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/stl_pair.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/move.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/concept_check.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/stl_iterator_base_types.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/stl_iterator_base_funcs.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/debug/debug.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/stl_iterator.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/ptr_traits.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/predefined_ops.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/allocator.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/x86_64-pc-linux-gnu/32/bits/c++allocator.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/ext/new_allocator.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/new \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/exception \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/atomic_lockfree_defines.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/memoryfwd.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/stl_construct.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/ext/alloc_traits.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/stl_uninitialized.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/stl_vector.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/stl_bvector.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/range_access.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/vector.tcc \
 ../machine/timer.h
utility.o: ../threads/utility.cc /usr/include/stdc-predef.h \
 ../threads/copyright.h ../threads/utility.h /usr/include/stdlib.h \
 /usr/include/features.h /usr/include/sys/cdefs.h \
 /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h \
 /usr/include/gnu/stubs-32.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/stddef.h \
 /usr/include/bits/waitflags.h /usr/include/bits/waitstatus.h \
 /usr/include/endian.h /usr/include/bits/endian.h \
 /usr/include/bits/byteswap.h /usr/include/bits/types.h \
 /usr/include/bits/typesizes.h /usr/include/bits/byteswap-16.h \
 /usr/include/xlocale.h /usr/include/sys/types.h /usr/include/time.h \
 /usr/include/sys/select.h /usr/include/bits/select.h \
 /usr/include/bits/sigset.h /usr/include/bits/time.h \
 /usr/include/sys/sysmacros.h /usr/include/bits/pthreadtypes.h \
 /usr/include/alloca.h /usr/include/bits/stdlib-float.h \
 ../machine/sysdep.h ../threads/copyright.h /usr/include/stdio.h \
 /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/stdarg.h \
 /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h \
 /usr/include/string.h /usr/include/errno.h /usr/include/bits/errno.h \
 /usr/include/linux/errno.h /usr/include/asm/errno.h \
 /usr/include/asm-generic/errno.h /usr/include/asm-generic/errno-base.h
threadtest.o: ../threads/threadtest.cc /usr/include/stdc-predef.h \
 ../threads/copyright.h ../threads/system.h ../threads/utility.h \
 /usr/include/stdlib.h /usr/include/features.h /usr/include/sys/cdefs.h \
 /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h \
 /usr/include/gnu/stubs-32.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/stddef.h \
 /usr/include/bits/waitflags.h /usr/include/bits/waitstatus.h \
 /usr/include/endian.h /usr/include/bits/endian.h \
 /usr/include/bits/byteswap.h /usr/include/bits/types.h \
 /usr/include/bits/typesizes.h /usr/include/bits/byteswap-16.h \
 /usr/include/xlocale.h /usr/include/sys/types.h /usr/include/time.h \
 /usr/include/sys/select.h /usr/include/bits/select.h \
 /usr/include/bits/sigset.h /usr/include/bits/time.h \
 /usr/include/sys/sysmacros.h /usr/include/bits/pthreadtypes.h \
 /usr/include/alloca.h /usr/include/bits/stdlib-float.h \
 ../machine/sysdep.h ../threads/copyright.h /usr/include/stdio.h \
 /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/stdarg.h \
 /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h \
 /usr/include/string.h ../threads/thread.h ../machine/machine.h \
 ../threads/utility.h ../machine/translate.h ../machine/disk.h \
 ../userprog/addrspace.h ../filesys/filesys.h ../filesys/openfile.h \
 ../threads/scheduler.h ../threads/list.h ../machine/interrupt.h \
 ../threads/list.h ../machine/stats.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/vector \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/stl_algobase.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/x86_64-pc-linux-gnu/32/bits/c++config.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/x86_64-pc-linux-gnu/32/bits/os_defines.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/x86_64-pc-linux-gnu/32/bits/cpu_defines.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/functexcept.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/exception_defines.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/cpp_type_traits.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/ext/type_traits.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/ext/numeric_traits.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/stl_pair.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/move.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/concept_check.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/stl_iterator_base_types.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/stl_iterator_base_funcs.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/debug/debug.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/stl_iterator.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/ptr_traits.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/predefined_ops.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/allocator.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/x86_64-pc-linux-gnu/32/bits/c++allocator.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/ext/new_allocator.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/new \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/exception \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/atomic_lockfree_defines.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/memoryfwd.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/stl_construct.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/ext/alloc_traits.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/stl_uninitialized.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/stl_vector.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/stl_bvector.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/range_access.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/vector.tcc \
 ../machine/timer.h
interrupt.o: ../machine/interrupt.cc /usr/include/stdc-predef.h \
 ../threads/copyright.h ../machine/interrupt.h ../threads/list.h \
 ../threads/copyright.h ../threads/utility.h /usr/include/stdlib.h \
 /usr/include/features.h /usr/include/sys/cdefs.h \
 /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h \
 /usr/include/gnu/stubs-32.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/stddef.h \
 /usr/include/bits/waitflags.h /usr/include/bits/waitstatus.h \
 /usr/include/endian.h /usr/include/bits/endian.h \
 /usr/include/bits/byteswap.h /usr/include/bits/types.h \
 /usr/include/bits/typesizes.h /usr/include/bits/byteswap-16.h \
 /usr/include/xlocale.h /usr/include/sys/types.h /usr/include/time.h \
 /usr/include/sys/select.h /usr/include/bits/select.h \
 /usr/include/bits/sigset.h /usr/include/bits/time.h \
 /usr/include/sys/sysmacros.h /usr/include/bits/pthreadtypes.h \
 /usr/include/alloca.h /usr/include/bits/stdlib-float.h \
 ../machine/sysdep.h /usr/include/stdio.h /usr/include/libio.h \
 /usr/include/_G_config.h /usr/include/wchar.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/stdarg.h \
 /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h \
 /usr/include/string.h ../threads/system.h ../threads/thread.h \
 ../machine/machine.h ../threads/utility.h ../machine/translate.h \
 ../machine/disk.h ../userprog/addrspace.h ../filesys/filesys.h \
 ../filesys/openfile.h ../threads/scheduler.h ../threads/list.h \
 ../machine/interrupt.h ../machine/stats.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/vector \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/stl_algobase.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/x86_64-pc-linux-gnu/32/bits/c++config.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/x86_64-pc-linux-gnu/32/bits/os_defines.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/x86_64-pc-linux-gnu/32/bits/cpu_defines.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/functexcept.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/exception_defines.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/cpp_type_traits.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/ext/type_traits.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/ext/numeric_traits.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/stl_pair.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/move.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/concept_check.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/stl_iterator_base_types.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/stl_iterator_base_funcs.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/debug/debug.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/stl_iterator.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/ptr_traits.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/predefined_ops.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/allocator.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/x86_64-pc-linux-gnu/32/bits/c++allocator.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/ext/new_allocator.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/new \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/exception \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/atomic_lockfree_defines.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/memoryfwd.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/stl_construct.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/ext/alloc_traits.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/stl_uninitialized.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/stl_vector.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/stl_bvector.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/range_access.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/vector.tcc \
 ../machine/timer.h
sysdep.o: ../machine/sysdep.cc /usr/include/stdc-predef.h \
 ../threads/copyright.h /usr/include/stdio.h /usr/include/features.h \
 /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h \
 /usr/include/gnu/stubs.h /usr/include/gnu/stubs-32.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/stddef.h \
 /usr/include/bits/types.h /usr/include/bits/typesizes.h \
 /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/stdarg.h \
 /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h \
 /usr/include/string.h /usr/include/xlocale.h /usr/include/signal.h \
 /usr/include/bits/sigset.h /usr/include/bits/signum.h \
 /usr/include/time.h /usr/include/bits/siginfo.h \
 /usr/include/bits/sigaction.h /usr/include/bits/sigcontext.h \
 /usr/include/bits/sigstack.h /usr/include/sys/ucontext.h \
 /usr/include/bits/pthreadtypes.h /usr/include/bits/sigthread.h \
 /usr/include/sys/types.h /usr/include/endian.h \
 /usr/include/bits/endian.h /usr/include/bits/byteswap.h \
 /usr/include/bits/byteswap-16.h /usr/include/sys/select.h \
 /usr/include/bits/select.h /usr/include/bits/time.h \
 /usr/include/sys/sysmacros.h /usr/include/sys/time.h \
 /usr/include/sys/socket.h /usr/include/sys/uio.h /usr/include/bits/uio.h \
 /usr/include/bits/socket.h /usr/include/bits/socket_type.h \
 /usr/include/bits/sockaddr.h /usr/include/asm/socket.h \
 /usr/include/asm-generic/socket.h /usr/include/asm/sockios.h \
 /usr/include/asm-generic/sockios.h /usr/include/sys/file.h \
 /usr/include/fcntl.h /usr/include/bits/fcntl.h \
 /usr/include/bits/fcntl-linux.h /usr/include/bits/stat.h \
 /usr/include/sys/un.h /usr/include/sys/mman.h /usr/include/bits/mman.h \
 /usr/include/bits/mman-linux.h /usr/include/unistd.h \
 /usr/include/bits/posix_opt.h /usr/include/bits/environments.h \
 /usr/include/bits/confname.h /usr/include/getopt.h /usr/include/stdlib.h \
 /usr/include/bits/waitflags.h /usr/include/bits/waitstatus.h \
 /usr/include/alloca.h /usr/include/bits/stdlib-float.h \
 /usr/include/errno.h /usr/include/bits/errno.h \
 /usr/include/linux/errno.h /usr/include/asm/errno.h \
 /usr/include/asm-generic/errno.h /usr/include/asm-generic/errno-base.h \
 ../machine/interrupt.h ../threads/list.h ../threads/copyright.h \
 ../threads/utility.h ../machine/sysdep.h ../threads/system.h \
 ../threads/thread.h ../machine/machine.h ../threads/utility.h \
 ../machine/translate.h ../machine/disk.h ../userprog/addrspace.h \
 ../filesys/filesys.h ../filesys/openfile.h ../threads/scheduler.h \
 ../threads/list.h ../machine/interrupt.h ../machine/stats.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/vector \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/stl_algobase.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/x86_64-pc-linux-gnu/32/bits/c++config.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/x86_64-pc-linux-gnu/32/bits/os_defines.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/x86_64-pc-linux-gnu/32/bits/cpu_defines.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/functexcept.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/exception_defines.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/cpp_type_traits.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/ext/type_traits.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/ext/numeric_traits.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/stl_pair.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/move.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/concept_check.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/stl_iterator_base_types.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/stl_iterator_base_funcs.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/debug/debug.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/stl_iterator.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/ptr_traits.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/predefined_ops.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/allocator.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/x86_64-pc-linux-gnu/32/bits/c++allocator.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/ext/new_allocator.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/new \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/exception \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/atomic_lockfree_defines.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/memoryfwd.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/stl_construct.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/ext/alloc_traits.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/stl_uninitialized.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/stl_vector.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/stl_bvector.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/range_access.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/vector.tcc \
 ../machine/timer.h
stats.o: ../machine/stats.cc /usr/include/stdc-predef.h \
 ../threads/copyright.h /usr/include/math.h /usr/include/features.h \
 /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h \
 /usr/include/gnu/stubs.h /usr/include/gnu/stubs-32.h \
 /usr/include/bits/math-vector.h /usr/include/bits/libm-simd-decl-stubs.h \
 /usr/include/bits/huge_val.h /usr/include/bits/huge_valf.h \
 /usr/include/bits/huge_vall.h /usr/include/bits/inf.h \
 /usr/include/bits/nan.h /usr/include/bits/mathdef.h \
 /usr/include/bits/mathcalls.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include-fixed/limits.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include-fixed/syslimits.h \
 /usr/include/limits.h /usr/include/bits/posix1_lim.h \
 /usr/include/bits/local_lim.h /usr/include/linux/limits.h \
 /usr/include/bits/posix2_lim.h /usr/include/bits/xopen_lim.h \
 /usr/include/bits/stdio_lim.h ../threads/utility.h \
 ../threads/copyright.h /usr/include/stdlib.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/stddef.h \
 /usr/include/bits/waitflags.h /usr/include/bits/waitstatus.h \
 /usr/include/endian.h /usr/include/bits/endian.h \
 /usr/include/bits/byteswap.h /usr/include/bits/types.h \
 /usr/include/bits/typesizes.h /usr/include/bits/byteswap-16.h \
 /usr/include/xlocale.h /usr/include/sys/types.h /usr/include/time.h \
 /usr/include/sys/select.h /usr/include/bits/select.h \
 /usr/include/bits/sigset.h /usr/include/bits/time.h \
 /usr/include/sys/sysmacros.h /usr/include/bits/pthreadtypes.h \
 /usr/include/alloca.h /usr/include/bits/stdlib-float.h \
 ../machine/sysdep.h /usr/include/stdio.h /usr/include/libio.h \
 /usr/include/_G_config.h /usr/include/wchar.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/stdarg.h \
 /usr/include/bits/sys_errlist.h /usr/include/string.h ../machine/stats.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/vector \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/stl_algobase.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/x86_64-pc-linux-gnu/32/bits/c++config.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/x86_64-pc-linux-gnu/32/bits/os_defines.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/x86_64-pc-linux-gnu/32/bits/cpu_defines.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/functexcept.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/exception_defines.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/cpp_type_traits.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/ext/type_traits.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/ext/numeric_traits.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/stl_pair.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/move.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/concept_check.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/stl_iterator_base_types.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/stl_iterator_base_funcs.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/debug/debug.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/stl_iterator.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/ptr_traits.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/predefined_ops.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/allocator.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/x86_64-pc-linux-gnu/32/bits/c++allocator.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/ext/new_allocator.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/new \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/exception \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/atomic_lockfree_defines.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/memoryfwd.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/stl_construct.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/ext/alloc_traits.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/stl_uninitialized.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/stl_vector.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/stl_bvector.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/range_access.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/vector.tcc
timer.o: ../machine/timer.cc /usr/include/stdc-predef.h \
 ../threads/copyright.h ../machine/timer.h ../threads/utility.h \
 ../threads/copyright.h /usr/include/stdlib.h /usr/include/features.h \
 /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h \
 /usr/include/gnu/stubs.h /usr/include/gnu/stubs-32.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/stddef.h \
 /usr/include/bits/waitflags.h /usr/include/bits/waitstatus.h \
 /usr/include/endian.h /usr/include/bits/endian.h \
 /usr/include/bits/byteswap.h /usr/include/bits/types.h \
 /usr/include/bits/typesizes.h /usr/include/bits/byteswap-16.h \
 /usr/include/xlocale.h /usr/include/sys/types.h /usr/include/time.h \
 /usr/include/sys/select.h /usr/include/bits/select.h \
 /usr/include/bits/sigset.h /usr/include/bits/time.h \
 /usr/include/sys/sysmacros.h /usr/include/bits/pthreadtypes.h \
 /usr/include/alloca.h /usr/include/bits/stdlib-float.h \
 ../machine/sysdep.h /usr/include/stdio.h /usr/include/libio.h \
 /usr/include/_G_config.h /usr/include/wchar.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/stdarg.h \
 /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h \
 /usr/include/string.h ../threads/system.h ../threads/utility.h \
 ../threads/thread.h ../machine/machine.h ../machine/translate.h \
 ../machine/disk.h ../userprog/addrspace.h ../filesys/filesys.h \
 ../filesys/openfile.h ../threads/scheduler.h ../threads/list.h \
 ../machine/interrupt.h ../threads/list.h ../machine/stats.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/vector \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/stl_algobase.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/x86_64-pc-linux-gnu/32/bits/c++config.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/x86_64-pc-linux-gnu/32/bits/os_defines.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/x86_64-pc-linux-gnu/32/bits/cpu_defines.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/functexcept.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/exception_defines.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/cpp_type_traits.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/ext/type_traits.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/ext/numeric_traits.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/stl_pair.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/move.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/concept_check.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/stl_iterator_base_types.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/stl_iterator_base_funcs.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/debug/debug.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/stl_iterator.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/ptr_traits.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/predefined_ops.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/allocator.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/x86_64-pc-linux-gnu/32/bits/c++allocator.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/ext/new_allocator.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/new \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/exception \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/atomic_lockfree_defines.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/memoryfwd.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/stl_construct.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/ext/alloc_traits.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/stl_uninitialized.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/stl_vector.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/stl_bvector.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/range_access.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/vector.tcc \
 ../machine/timer.h
addrspace.o: ../userprog/addrspace.cc /usr/include/stdc-predef.h \
 ../threads/copyright.h ../threads/system.h ../threads/copyright.h \
 ../threads/utility.h /usr/include/stdlib.h /usr/include/features.h \
 /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h \
 /usr/include/gnu/stubs.h /usr/include/gnu/stubs-32.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/stddef.h \
 /usr/include/bits/waitflags.h /usr/include/bits/waitstatus.h \
 /usr/include/endian.h /usr/include/bits/endian.h \
 /usr/include/bits/byteswap.h /usr/include/bits/types.h \
 /usr/include/bits/typesizes.h /usr/include/bits/byteswap-16.h \
 /usr/include/xlocale.h /usr/include/sys/types.h /usr/include/time.h \
 /usr/include/sys/select.h /usr/include/bits/select.h \
 /usr/include/bits/sigset.h /usr/include/bits/time.h \
 /usr/include/sys/sysmacros.h /usr/include/bits/pthreadtypes.h \
 /usr/include/alloca.h /usr/include/bits/stdlib-float.h \
 ../machine/sysdep.h /usr/include/stdio.h /usr/include/libio.h \
 /usr/include/_G_config.h /usr/include/wchar.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/stdarg.h \
 /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h \
 /usr/include/string.h ../threads/thread.h ../machine/machine.h \
 ../threads/utility.h ../machine/translate.h ../machine/disk.h \
 ../userprog/addrspace.h ../filesys/filesys.h ../filesys/openfile.h \
 ../threads/scheduler.h ../threads/list.h ../machine/interrupt.h \
 ../threads/list.h ../machine/stats.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/vector \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/stl_algobase.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/x86_64-pc-linux-gnu/32/bits/c++config.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/x86_64-pc-linux-gnu/32/bits/os_defines.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/x86_64-pc-linux-gnu/32/bits/cpu_defines.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/functexcept.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/exception_defines.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/cpp_type_traits.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/ext/type_traits.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/ext/numeric_traits.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/stl_pair.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/move.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/concept_check.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/stl_iterator_base_types.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/stl_iterator_base_funcs.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/debug/debug.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/stl_iterator.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/ptr_traits.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/predefined_ops.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/allocator.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/x86_64-pc-linux-gnu/32/bits/c++allocator.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/ext/new_allocator.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/new \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/exception \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/atomic_lockfree_defines.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/memoryfwd.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/stl_construct.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/ext/alloc_traits.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/stl_uninitialized.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/stl_vector.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/stl_bvector.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/range_access.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/vector.tcc \
 ../machine/timer.h ../userprog/addrspace.h ../bin/noff.h
bitmap.o: ../userprog/bitmap.cc /usr/include/stdc-predef.h \
 ../threads/copyright.h ../userprog/bitmap.h ../threads/utility.h \
 ../threads/copyright.h /usr/include/stdlib.h /usr/include/features.h \
 /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h \
 /usr/include/gnu/stubs.h /usr/include/gnu/stubs-32.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/stddef.h \
 /usr/include/bits/waitflags.h /usr/include/bits/waitstatus.h \
 /usr/include/endian.h /usr/include/bits/endian.h \
 /usr/include/bits/byteswap.h /usr/include/bits/types.h \
 /usr/include/bits/typesizes.h /usr/include/bits/byteswap-16.h \
 /usr/include/xlocale.h /usr/include/sys/types.h /usr/include/time.h \
 /usr/include/sys/select.h /usr/include/bits/select.h \
 /usr/include/bits/sigset.h /usr/include/bits/time.h \
 /usr/include/sys/sysmacros.h /usr/include/bits/pthreadtypes.h \
 /usr/include/alloca.h /usr/include/bits/stdlib-float.h \
 ../machine/sysdep.h /usr/include/stdio.h /usr/include/libio.h \
 /usr/include/_G_config.h /usr/include/wchar.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/stdarg.h \
 /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h \
 /usr/include/string.h ../filesys/openfile.h
exception.o: ../userprog/exception.cc /usr/include/stdc-predef.h \
 ../threads/copyright.h ../threads/system.h ../threads/copyright.h \
 ../threads/utility.h /usr/include/stdlib.h /usr/include/features.h \
 /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h \
 /usr/include/gnu/stubs.h /usr/include/gnu/stubs-32.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/stddef.h \
 /usr/include/bits/waitflags.h /usr/include/bits/waitstatus.h \
 /usr/include/endian.h /usr/include/bits/endian.h \
 /usr/include/bits/byteswap.h /usr/include/bits/types.h \
 /usr/include/bits/typesizes.h /usr/include/bits/byteswap-16.h \
 /usr/include/xlocale.h /usr/include/sys/types.h /usr/include/time.h \
 /usr/include/sys/select.h /usr/include/bits/select.h \
 /usr/include/bits/sigset.h /usr/include/bits/time.h \
 /usr/include/sys/sysmacros.h /usr/include/bits/pthreadtypes.h \
 /usr/include/alloca.h /usr/include/bits/stdlib-float.h \
 ../machine/sysdep.h /usr/include/stdio.h /usr/include/libio.h \
 /usr/include/_G_config.h /usr/include/wchar.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/stdarg.h \
 /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h \
 /usr/include/string.h ../threads/thread.h ../machine/machine.h \
 ../threads/utility.h ../machine/translate.h ../machine/disk.h \
 ../userprog/addrspace.h ../filesys/filesys.h ../filesys/openfile.h \
 ../threads/scheduler.h ../threads/list.h ../machine/interrupt.h \
 ../threads/list.h ../machine/stats.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/vector \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/stl_algobase.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/x86_64-pc-linux-gnu/32/bits/c++config.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/x86_64-pc-linux-gnu/32/bits/os_defines.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/x86_64-pc-linux-gnu/32/bits/cpu_defines.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/functexcept.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/exception_defines.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/cpp_type_traits.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/ext/type_traits.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/ext/numeric_traits.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/stl_pair.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/move.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/concept_check.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/stl_iterator_base_types.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/stl_iterator_base_funcs.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/debug/debug.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/stl_iterator.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/ptr_traits.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/predefined_ops.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/allocator.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/x86_64-pc-linux-gnu/32/bits/c++allocator.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/ext/new_allocator.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/new \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/exception \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/atomic_lockfree_defines.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/memoryfwd.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/stl_construct.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/ext/alloc_traits.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/stl_uninitialized.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/stl_vector.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/stl_bvector.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/range_access.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/vector.tcc \
 ../machine/timer.h ../userprog/syscall.h ../machine/console.h \
 ../threads/synch.h
progtest.o: ../userprog/progtest.cc /usr/include/stdc-predef.h \
 ../threads/copyright.h ../threads/system.h ../threads/copyright.h \
 ../threads/utility.h /usr/include/stdlib.h /usr/include/features.h \
 /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h \
 /usr/include/gnu/stubs.h /usr/include/gnu/stubs-32.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/stddef.h \
 /usr/include/bits/waitflags.h /usr/include/bits/waitstatus.h \
 /usr/include/endian.h /usr/include/bits/endian.h \
 /usr/include/bits/byteswap.h /usr/include/bits/types.h \
 /usr/include/bits/typesizes.h /usr/include/bits/byteswap-16.h \
 /usr/include/xlocale.h /usr/include/sys/types.h /usr/include/time.h \
 /usr/include/sys/select.h /usr/include/bits/select.h \
 /usr/include/bits/sigset.h /usr/include/bits/time.h \
 /usr/include/sys/sysmacros.h /usr/include/bits/pthreadtypes.h \
 /usr/include/alloca.h /usr/include/bits/stdlib-float.h \
 ../machine/sysdep.h /usr/include/stdio.h /usr/include/libio.h \
 /usr/include/_G_config.h /usr/include/wchar.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/stdarg.h \
 /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h \
 /usr/include/string.h ../threads/thread.h ../machine/machine.h \
 ../threads/utility.h ../machine/translate.h ../machine/disk.h \
 ../userprog/addrspace.h ../filesys/filesys.h ../filesys/openfile.h \
 ../threads/scheduler.h ../threads/list.h ../machine/interrupt.h \
 ../threads/list.h ../machine/stats.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/vector \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/stl_algobase.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/x86_64-pc-linux-gnu/32/bits/c++config.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/x86_64-pc-linux-gnu/32/bits/os_defines.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/x86_64-pc-linux-gnu/32/bits/cpu_defines.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/functexcept.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/exception_defines.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/cpp_type_traits.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/ext/type_traits.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/ext/numeric_traits.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/stl_pair.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/move.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/concept_check.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/stl_iterator_base_types.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/stl_iterator_base_funcs.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/debug/debug.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/stl_iterator.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/ptr_traits.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/predefined_ops.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/allocator.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/x86_64-pc-linux-gnu/32/bits/c++allocator.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/ext/new_allocator.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/new \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/exception \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/atomic_lockfree_defines.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/memoryfwd.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/stl_construct.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/ext/alloc_traits.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/stl_uninitialized.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/stl_vector.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/stl_bvector.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/range_access.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/vector.tcc \
 ../machine/timer.h ../machine/console.h ../userprog/addrspace.h \
 ../threads/synch.h
console.o: ../machine/console.cc /usr/include/stdc-predef.h \
 ../threads/copyright.h ../machine/console.h ../threads/utility.h \
 ../threads/copyright.h /usr/include/stdlib.h /usr/include/features.h \
 /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h \
 /usr/include/gnu/stubs.h /usr/include/gnu/stubs-32.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/stddef.h \
 /usr/include/bits/waitflags.h /usr/include/bits/waitstatus.h \
 /usr/include/endian.h /usr/include/bits/endian.h \
 /usr/include/bits/byteswap.h /usr/include/bits/types.h \
 /usr/include/bits/typesizes.h /usr/include/bits/byteswap-16.h \
 /usr/include/xlocale.h /usr/include/sys/types.h /usr/include/time.h \
 /usr/include/sys/select.h /usr/include/bits/select.h \
 /usr/include/bits/sigset.h /usr/include/bits/time.h \
 /usr/include/sys/sysmacros.h /usr/include/bits/pthreadtypes.h \
 /usr/include/alloca.h /usr/include/bits/stdlib-float.h \
 ../machine/sysdep.h /usr/include/stdio.h /usr/include/libio.h \
 /usr/include/_G_config.h /usr/include/wchar.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/stdarg.h \
 /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h \
 /usr/include/string.h ../threads/system.h ../threads/utility.h \
 ../threads/thread.h ../machine/machine.h ../machine/translate.h \
 ../machine/disk.h ../userprog/addrspace.h ../filesys/filesys.h \
 ../filesys/openfile.h ../threads/scheduler.h ../threads/list.h \
 ../machine/interrupt.h ../threads/list.h ../machine/stats.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/vector \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/stl_algobase.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/x86_64-pc-linux-gnu/32/bits/c++config.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/x86_64-pc-linux-gnu/32/bits/os_defines.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/x86_64-pc-linux-gnu/32/bits/cpu_defines.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/functexcept.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/exception_defines.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/cpp_type_traits.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/ext/type_traits.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/ext/numeric_traits.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/stl_pair.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/move.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/concept_check.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/stl_iterator_base_types.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/stl_iterator_base_funcs.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/debug/debug.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/stl_iterator.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/ptr_traits.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/predefined_ops.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/allocator.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/x86_64-pc-linux-gnu/32/bits/c++allocator.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/ext/new_allocator.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/new \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/exception \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/atomic_lockfree_defines.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/memoryfwd.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/stl_construct.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/ext/alloc_traits.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/stl_uninitialized.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/stl_vector.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/stl_bvector.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/range_access.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/vector.tcc \
 ../machine/timer.h
machine.o: ../machine/machine.cc /usr/include/stdc-predef.h \
 ../threads/copyright.h ../machine/machine.h ../threads/utility.h \
 ../threads/copyright.h /usr/include/stdlib.h /usr/include/features.h \
 /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h \
 /usr/include/gnu/stubs.h /usr/include/gnu/stubs-32.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/stddef.h \
 /usr/include/bits/waitflags.h /usr/include/bits/waitstatus.h \
 /usr/include/endian.h /usr/include/bits/endian.h \
 /usr/include/bits/byteswap.h /usr/include/bits/types.h \
 /usr/include/bits/typesizes.h /usr/include/bits/byteswap-16.h \
 /usr/include/xlocale.h /usr/include/sys/types.h /usr/include/time.h \
 /usr/include/sys/select.h /usr/include/bits/select.h \
 /usr/include/bits/sigset.h /usr/include/bits/time.h \
 /usr/include/sys/sysmacros.h /usr/include/bits/pthreadtypes.h \
 /usr/include/alloca.h /usr/include/bits/stdlib-float.h \
 ../machine/sysdep.h /usr/include/stdio.h /usr/include/libio.h \
 /usr/include/_G_config.h /usr/include/wchar.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/stdarg.h \
 /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h \
 /usr/include/string.h ../machine/translate.h ../machine/disk.h \
 ../threads/system.h ../threads/utility.h ../threads/thread.h \
 ../machine/machine.h ../userprog/addrspace.h ../filesys/filesys.h \
 ../filesys/openfile.h ../threads/scheduler.h ../threads/list.h \
 ../machine/interrupt.h ../threads/list.h ../machine/stats.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/vector \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/stl_algobase.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/x86_64-pc-linux-gnu/32/bits/c++config.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/x86_64-pc-linux-gnu/32/bits/os_defines.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/x86_64-pc-linux-gnu/32/bits/cpu_defines.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/functexcept.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/exception_defines.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/cpp_type_traits.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/ext/type_traits.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/ext/numeric_traits.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/stl_pair.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/move.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/concept_check.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/stl_iterator_base_types.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/stl_iterator_base_funcs.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/debug/debug.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/stl_iterator.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/ptr_traits.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/predefined_ops.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/allocator.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/x86_64-pc-linux-gnu/32/bits/c++allocator.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/ext/new_allocator.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/new \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/exception \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/atomic_lockfree_defines.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/memoryfwd.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/stl_construct.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/ext/alloc_traits.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/stl_uninitialized.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/stl_vector.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/stl_bvector.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/range_access.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/vector.tcc \
 ../machine/timer.h
mipssim.o: ../machine/mipssim.cc /usr/include/stdc-predef.h \
 ../threads/copyright.h ../machine/machine.h ../threads/utility.h \
 ../threads/copyright.h /usr/include/stdlib.h /usr/include/features.h \
 /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h \
 /usr/include/gnu/stubs.h /usr/include/gnu/stubs-32.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/stddef.h \
 /usr/include/bits/waitflags.h /usr/include/bits/waitstatus.h \
 /usr/include/endian.h /usr/include/bits/endian.h \
 /usr/include/bits/byteswap.h /usr/include/bits/types.h \
 /usr/include/bits/typesizes.h /usr/include/bits/byteswap-16.h \
 /usr/include/xlocale.h /usr/include/sys/types.h /usr/include/time.h \
 /usr/include/sys/select.h /usr/include/bits/select.h \
 /usr/include/bits/sigset.h /usr/include/bits/time.h \
 /usr/include/sys/sysmacros.h /usr/include/bits/pthreadtypes.h \
 /usr/include/alloca.h /usr/include/bits/stdlib-float.h \
 ../machine/sysdep.h /usr/include/stdio.h /usr/include/libio.h \
 /usr/include/_G_config.h /usr/include/wchar.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/stdarg.h \
 /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h \
 /usr/include/string.h ../machine/translate.h ../machine/disk.h \
 ../machine/mipssim.h ../threads/system.h ../threads/utility.h \
 ../threads/thread.h ../machine/machine.h ../userprog/addrspace.h \
 ../filesys/filesys.h ../filesys/openfile.h ../threads/scheduler.h \
 ../threads/list.h ../machine/interrupt.h ../threads/list.h \
 ../machine/stats.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/vector \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/stl_algobase.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/x86_64-pc-linux-gnu/32/bits/c++config.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/x86_64-pc-linux-gnu/32/bits/os_defines.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/x86_64-pc-linux-gnu/32/bits/cpu_defines.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/functexcept.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/exception_defines.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/cpp_type_traits.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/ext/type_traits.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/ext/numeric_traits.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/stl_pair.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/move.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/concept_check.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/stl_iterator_base_types.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/stl_iterator_base_funcs.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/debug/debug.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/stl_iterator.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/ptr_traits.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/predefined_ops.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/allocator.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/x86_64-pc-linux-gnu/32/bits/c++allocator.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/ext/new_allocator.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/new \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/exception \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/atomic_lockfree_defines.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/memoryfwd.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/stl_construct.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/ext/alloc_traits.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/stl_uninitialized.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/stl_vector.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/stl_bvector.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/range_access.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/vector.tcc \
 ../machine/timer.h
translate.o: ../machine/translate.cc /usr/include/stdc-predef.h \
 ../threads/copyright.h ../machine/machine.h ../threads/utility.h \
 ../threads/copyright.h /usr/include/stdlib.h /usr/include/features.h \
 /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h \
 /usr/include/gnu/stubs.h /usr/include/gnu/stubs-32.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/stddef.h \
 /usr/include/bits/waitflags.h /usr/include/bits/waitstatus.h \
 /usr/include/endian.h /usr/include/bits/endian.h \
 /usr/include/bits/byteswap.h /usr/include/bits/types.h \
 /usr/include/bits/typesizes.h /usr/include/bits/byteswap-16.h \
 /usr/include/xlocale.h /usr/include/sys/types.h /usr/include/time.h \
 /usr/include/sys/select.h /usr/include/bits/select.h \
 /usr/include/bits/sigset.h /usr/include/bits/time.h \
 /usr/include/sys/sysmacros.h /usr/include/bits/pthreadtypes.h \
 /usr/include/alloca.h /usr/include/bits/stdlib-float.h \
 ../machine/sysdep.h /usr/include/stdio.h /usr/include/libio.h \
 /usr/include/_G_config.h /usr/include/wchar.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/stdarg.h \
 /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h \
 /usr/include/string.h ../machine/translate.h ../machine/disk.h \
 ../userprog/addrspace.h ../filesys/filesys.h ../filesys/openfile.h \
 ../threads/system.h ../threads/utility.h ../threads/thread.h \
 ../machine/machine.h ../threads/scheduler.h ../threads/list.h \
 ../machine/interrupt.h ../threads/list.h ../machine/stats.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/vector \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/stl_algobase.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/x86_64-pc-linux-gnu/32/bits/c++config.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/x86_64-pc-linux-gnu/32/bits/os_defines.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/x86_64-pc-linux-gnu/32/bits/cpu_defines.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/functexcept.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/exception_defines.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/cpp_type_traits.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/ext/type_traits.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/ext/numeric_traits.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/stl_pair.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/move.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/concept_check.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/stl_iterator_base_types.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/stl_iterator_base_funcs.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/debug/debug.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/stl_iterator.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/ptr_traits.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/predefined_ops.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/allocator.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/x86_64-pc-linux-gnu/32/bits/c++allocator.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/ext/new_allocator.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/new \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/exception \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/atomic_lockfree_defines.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/memoryfwd.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/stl_construct.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/ext/alloc_traits.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/stl_uninitialized.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/stl_vector.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/stl_bvector.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/range_access.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.3/include/g++-v4/bits/vector.tcc \
 ../machine/timer.h
# DEPENDENCIES MUST END AT END OF FILE
# IF YOU PUT STUFF HERE IT WILL GO AWAY
# see make depend above
