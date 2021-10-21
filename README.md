# natvis `ArrayItems` `Condition` issue

Repro steps:

1. Load `VS2019_natvis_ArrayItems_condition.sln` into Visual Studio
   2019.
   
   The project contain contains example uses of two simplified
   template array classes `Array1` and `Array2`, and corresponding use
   of `std::vector`.
   
   There is a .natvis file that's intended to let you view the
   contents of `Array1` and `Array2` objects in the debugger.
   
2. Build either `Debug`/`Win32` or `Debug`/`x64`

3. Put a breakpoint on the `printf` in `main.cpp`

4. Use `Debug` > `Start Debugging` to start debugging

5. Add the following entries to the watch window:

       test_vec
       test_vec[0]
       test_array1
       test_array1[0]
       test_array2
       test_array2[0]
       
# Actual results

Watch window contents:

    +       test_vec    { size=8 }  std::vector<int,std::allocator<int>>
            test_vec[0] 1   int
    +       test_array1 8   Array1<int>
            test_array1[0]  1   int
    +       test_array2 8   Array2<int>
            test_array2[0]  no operator "[]" matches these operands 

`test_vec` and `test_array1` are behaving as expected.

It seems the presence of `Condition` in the `ArrayItems` for `Array2`
stops the [] operator working.

# Expected results

Watch window contents:

    +       test_vec    { size=8 }  std::vector<int,std::allocator<int>>
            test_vec[0] 1   int
    +       test_array1 8   Array1<int>
            test_array1[0]  1   int
    +       test_array2 8   Array2<int>
            test_array2[0]  1   int

# Other notes

If you examine `test_vec` or `test_array1` using `Debug` >
`Quickwatch...`, when highlighting items of the array in turn you'll
see the quick watch expression change to something like `test_vec[0]`,
`test_vec[1]`, `test_array1[0]`... - and so on.

When examining `test_array2` in the same way, note that the expression
given for each item is `test_array2.p[0]`, `test_array2.p[1]`... - the
underlying expression as per the natvis specification.

