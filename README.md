# HookVirtualMethod
A function used to hook VMT entries.

THIS FUNCTION CAN ONLY BE USED BY A DLL LOADED INTO A PROCESS (ie. via injection or otherwise)

It makes NO guarantees about memory safety, you have to make sure the pointer you are feeding it is one of a class instance WITH a virtual method table. If it does not have any virtual methods, it doesn't have a virtual method table.

Use GetVirtualMethod before hooking to be able to call the original function if need be.
