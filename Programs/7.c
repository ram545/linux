/**********************************************************************
* FILENAME:        6.c

* AUTHOR: 20020298 | Rama Krishna | sabbella.krishna@wipro.com
* START DATE: 02/11/2019
* SUBMISSION DATE: 02/11/2019

**********************************************************************/



/*

The following was observed when we run the commands file,size and nm on the executables


1. file command determines the type of command and returns the output in ASCII Format.


2. size : gives the split in linux process address space

	text    data     bss     dec     hex filename
	1449     220      32    1701     6a5 ./a.out

3. nm : gives the symbols used in the executable file.

080496e0 d _DYNAMIC
08049778 d _GLOBAL_OFFSET_TABLE_
         w _ITM_deregisterTMCloneTable
         w _ITM_registerTMCloneTable
         w _Jv_RegisterClasses
080496d0 d __CTOR_END__
080496cc d __CTOR_LIST__
080496d8 D __DTOR_END__
080496d4 d __DTOR_LIST__
0804867c r __EH_FRAME_BEGIN__
080486c8 r __FRAME_END__
080496dc d __JCR_END__
080496dc d __JCR_LIST__
080497a8 D __TMC_END__
080497a8 B __bss_start
080497a0 D __data_start
         w __deregister_frame_info_bases
0804859c t __do_global_ctors_aux
080483d5 t __do_global_dtors_aux
080497a4 D __dso_handle
08048372 T __get_pc_thunk_bx
         w __register_frame_info_bases
         U __uClibc_main
080497a8 D _edata
080497c8 B _end
080485b8 T _fini
080482a8 T _init
08048350 T _start
080497a8 b completed.6049
080497a0 W data_start
08048376 t deregister_tm_clones
080497ac b dtor_idx.6051
         U exit
         U fork
08048488 T forking
08048436 t frame_dummy
08048571 T main
080497b0 b object.6061
         U printf
         U puts
080483a0 t register_tm_clones
         U sleep
         U waitpid


*/		 