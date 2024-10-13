# TRIAL RUN 12 bits

```
Γ¥» ./main
The program does the following:
 1. Generate a random byte array of 1 MB long.
 2. Hash the string using SHA256.
 3. If the first n bits of the hash are all 0s, save the byte array as fileXX
 4. Loop until file10.

[2024-10-13 23:03:12] INFO: Iterations: 0
...
[2024-10-13 23:03:59] INFO: Found file1... took 46790.824000 ms
...
[2024-10-13 23:05:21] INFO: Found file2... took 81608.870000 ms
...
^C

Γ¥» sha256sum file*
0000f1a7d81b046f73d7a8290fdadd4d0d480435894350da2fcdcd352c7b51d7  file0
00000696c53cb214dda68fb9febb561c8688b4e4d9a4b335af2791ea0d225ffa  file1
```

# 8 bits only
```
Γ¥» ./main
The program does the following:
 1. Generate a random byte array of 1 MB long.
 2. Hash the string using SHA256.
 3. If the first n bits of the hash are all 0s, save the byte array as fileXX
 4. Loop until file10.

[2024-10-13 23:08:01] INFO: Iterations: 0
[2024-10-13 23:08:01] INFO: Found file1... took 334.540000 ms
[2024-10-13 23:08:01] INFO: Found file2... took 232.863000 ms
[2024-10-13 23:08:03] INFO: Found file3... took 1908.025000 ms
[2024-10-13 23:08:05] INFO: Found file4... took 1481.183000 ms
[2024-10-13 23:08:08] INFO: Iterations: 1000
[2024-10-13 23:08:10] INFO: Found file5... took 5584.880000 ms
[2024-10-13 23:08:11] INFO: Found file6... took 374.809000 ms
[2024-10-13 23:08:14] INFO: Found file7... took 3026.049000 ms
[2024-10-13 23:08:14] INFO: Found file8... took 187.340000 ms
[2024-10-13 23:08:15] INFO: Iterations: 2000
[2024-10-13 23:08:20] INFO: Found file9... took 6146.684000 ms
[2024-10-13 23:08:20] INFO: Found file10... took 450.862000 ms
[2024-10-13 23:08:20] INFO: Found 10 files in 2765 iterations

Γ¥» sha256sum file*
00ff067c67ae53eb6bfbf86e8e3b5f8d606f94d2e2db26a821ec0066de074a06  file0
005fa9e01c73b4bbdccfb9185b5bbc7e3d0b0ccad331560f380b963e091654e4  file1
00347b95737bf4e01926b4fcecd988ee9afd3d0ac63b850dbf6aba0c7c0473c2  file2
003f43468cb9cee37657868451fbfe54f85b6b1e6c49328956ecbdb1bae6eb8d  file3
00d45dae25d7f8764bf441161bb028ab380e6e21ea36d1bed144030ccdcc6db8  file4
0085812b997710c6fd111db1de10235eb64a0d70a15a1f4ba76265b7fd0272aa  file5
0086dc39678c8a967b057e955d216acac66a6e9f25b9d1e6318213dd4c8ef5c9  file6
008f448636e03590729b986a99586bd7d9f196e6144bdf04d3fd91280c9e48f0  file7
00331b9183c8ad4f011d895aee717e9749437520fdd4dc4a5e501ad01357d4f5  file8
00a086fdc4bc7ab6f5e88d5f623d56feebaa93d9bf9b744a781607297336de4e  file9

```
