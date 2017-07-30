# Accessing data after memory has been freed


c언어로 linkedlist를 구현하는 과정에서 메모리 동적할당에 관해 문제가 생겼다.



    jLinkedlist *jLinkedlistNew () {
      jLinkedlist *newLinkedlist = (jLinkedlist *)malloc(sizeof(jLinkedlist));
      newLinkedlist->size = 0;
      newLinkedlist->first = NULL;
      newLinkedlist->last = NULL;
      free(newLinkedlist);
      printf("teset\n");
      printf("%d\n", newLinkedlist->size);
      return newLinkedlist;
    }
    

위의 코드에서 결과값이 0이 나오는 것이다.

분명히 나는 메모리 해제를 시켰는데 어떻게 newLinkedlist의 struct에 접근할 수 있는지 의문이였다.

stackoverflow를 검색하여 이에 관한 내용을 찾아보았다.
https://stackoverflow.com/questions/42588482/c-accessing-data-after-memory-has-been-freeed

이에 관해서 OS에 관련된 내용이 나왔다.

아마 malloc을 구현하는 과정에서 os마다 다른데 segmentation fault가 뜰 수도 있고 여전히 접근이 가능할 수도 있다는 것이다.

이에 관해서 valgrind라는 프로그램을 쓰면 메모리 누수를 체크할 수 있다는 정보를 확인했다.

http://forum.falinux.com/zbxe/index.php?document_srl=528619&mid=lecture_tip


    ==21689== Memcheck, a memory error detector
    ==21689== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
    ==21689== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
    ==21689== Command: ./a.out
    ==21689== 
    ==21689== Syscall param msg->desc.port.name points to uninitialised byte(s)
    ==21689==    at 0x1003AA34A: mach_msg_trap (in /usr/lib/system/libsystem_kernel.dylib)
    ==21689==    by 0x1003A9796: mach_msg (in /usr/lib/system/libsystem_kernel.dylib)
    ==21689==    by 0x1003A3485: task_set_special_port (in /usr/lib/system/libsystem_kernel.dylib)
    ==21689==    by 0x10053F10E: _os_trace_create_debug_control_port (in /usr/lib/system/libsystem_trace.dylib)
    ==21689==    by 0x10053F458: _libtrace_init (in /usr/lib/system/libsystem_trace.dylib)
    ==21689==    by 0x1000A89DF: libSystem_initializer (in /usr/lib/libSystem.B.dylib)
    ==21689==    by 0x10001AA1A: ImageLoaderMachO::doModInitFunctions(ImageLoader::LinkContext const&) (in /usr/lib/dyld)
    ==21689==    by 0x10001AC1D: ImageLoaderMachO::doInitialization(ImageLoader::LinkContext const&) (in /usr/lib/dyld)
    ==21689==    by 0x1000164A9: ImageLoader::recursiveInitialization(ImageLoader::LinkContext const&, unsigned int, char const*, ImageLoader::InitializerTimingList&, ImageLoader::UninitedUpwards&) (in /usr/lib/dyld)
    ==21689==    by 0x100016440: ImageLoader::recursiveInitialization(ImageLoader::LinkContext const&, unsigned int, char const*, ImageLoader::InitializerTimingList&, ImageLoader::UninitedUpwards&) (in /usr/lib/dyld)
    ==21689==    by 0x100015523: ImageLoader::processInitializers(ImageLoader::LinkContext const&, unsigned int, ImageLoader::InitializerTimingList&, ImageLoader::UninitedUpwards&) (in /usr/lib/dyld)
    ==21689==    by 0x1000155B8: ImageLoader::runInitializers(ImageLoader::LinkContext const&, ImageLoader::InitializerTimingList&) (in /usr/lib/dyld)
    ==21689==  Address 0x10488d86c is on thread 1's stack
    ==21689==  in frame #2, created by task_set_special_port (???:)
    ==21689== 
    test New....OK
    test Size....OK
    test Push....OK
    test Capacity....OK
    test IsEmpty....Ok
    test Insert....OK
    Test Prepend....OK
    Test Pop....OK
    Test Delete....OK
    Test Find....OK
    Test Remove....OK
    Test Resize....OK
    ==21689== 
    ==21689== HEAP SUMMARY:
    ==21689==     in use at exit: 22,122 bytes in 160 blocks
    ==21689==   total heap usage: 223 allocs, 63 frees, 30,058 bytes allocated
    ==21689== 
    ==21689== 72 bytes in 3 blocks are possibly lost in loss record 26 of 43
    ==21689==    at 0x10009AC7A: calloc (in /usr/local/Cellar/valgrind/3.13.0/lib/valgrind/vgpreload_memcheck-amd64-darwin.so)
    ==21689==    by 0x1005B3846: map_images_nolock (in /usr/lib/libobjc.A.dylib)
    ==21689==    by 0x1005C6FE8: objc_object::sidetable_retainCount() (in /usr/lib/libobjc.A.dylib)
    ==21689==    by 0x10000A03B: dyld::notifyBatchPartial(dyld_image_states, bool, char const* (*)(dyld_image_states, unsigned int, dyld_image_info const*), bool, bool) (in /usr/lib/dyld)
    ==21689==    by 0x10000A255: dyld::registerObjCNotifiers(void (*)(unsigned int, char const* const*, mach_header const* const*), void (*)(char const*, mach_header const*), void (*)(char const*, mach_header const*)) (in /usr/lib/dyld)
    ==21689==    by 0x10020100A: _dyld_objc_notify_register (in /usr/lib/system/libdyld.dylib)
    ==21689==    by 0x1005B3074: _objc_init (in /usr/lib/libobjc.A.dylib)
    ==21689==    by 0x10019468D: _os_object_init (in /usr/lib/system/libdispatch.dylib)
    ==21689==    by 0x10019463A: libdispatch_init (in /usr/lib/system/libdispatch.dylib)
    ==21689==    by 0x1000A89D5: libSystem_initializer (in /usr/lib/libSystem.B.dylib)
    ==21689==    by 0x10001AA1A: ImageLoaderMachO::doModInitFunctions(ImageLoader::LinkContext const&) (in /usr/lib/dyld)
    ==21689==    by 0x10001AC1D: ImageLoaderMachO::doInitialization(ImageLoader::LinkContext const&) (in /usr/lib/dyld)
    ==21689== 
    ==21689== LEAK SUMMARY:
    ==21689==    definitely lost: 0 bytes in 0 blocks
    ==21689==    indirectly lost: 0 bytes in 0 blocks
    ==21689==      possibly lost: 72 bytes in 3 blocks
    ==21689==    still reachable: 200 bytes in 6 blocks
    ==21689==         suppressed: 21,850 bytes in 151 blocks
    ==21689== Reachable blocks (those to which a pointer was found) are not shown.
    ==21689== To see them, rerun with: --leak-check=full --show-leak-kinds=all
    ==21689== 
    ==21689== For counts of detected and suppressed errors, rerun with: -v
    ==21689== Use --track-origins=yes to see where uninitialised values come from
    ==21689== ERROR SUMMARY: 2 errors from 2 contexts (suppressed: 12 from 12)

다음과 같이 뜨는데 결론적으로 `definitely lost: 0 bytes in 0 blocks`이니 누수가 없다고 보면 되겠다.

