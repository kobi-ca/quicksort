Original page from geeksforgeeks https://www.geeksforgeeks.org/quick-sort/

Benchmarks using online quick-bench.com:

Using lambda to compare - 1.8 or 2 slower
* clang https://quick-bench.com/q/noQrwHes7bostcZWf-Re-UYNupI  
* gcc https://quick-bench.com/q/du473pP_5EtjkDERriGo6lAPhqw  

with do-not-optimize (is_sorted)
* gcc https://quick-bench.com/q/rl0q6WdjTQGaiGLXEIlZzKpCXOQ  

new with span passed by value
needed to install gcc/g++ 10 to get span<> header  
Short arrays - clang is better
* clang https://quick-bench.com/q/XHbMmCyOVBdaBou4HXwjm4fMUH0    
* gcc https://quick-bench.com/q/kHUzN7RX8ru2S4w3YqQd62uKSic  (has different code from clang - has if (!p))
* gcc that is matching clang code https://quick-bench.com/q/AuRCkW6mgAKrdNrzcGDGOwKm6Gk

longer arrays - clang is also worse now
* clang with longer array - https://quick-bench.com/q/lyhlujUDBvQCyFViySM4p6BSGGg clang is now also worse
* gcc with longer array https://quick-bench.com/q/bvxPs7WGljvdIiknvJKbqHq-8Fs

longer arrays with const& span<>
* clang - https://quick-bench.com/q/J4LSs7P0Sah7w2cgzLb3W1Z2eZ0
* gcc - https://quick-bench.com/q/3I3kJYTY-SFe6wCiJ9JjbhLqNW4

Bypassing span, using to_array - without pivot, O3 long arrays (ignore for now)
* clang - https://quick-bench.com/q/e35tkMiRGtyvjJR88nWJ6gLN_So  (ignore it)

without pivot compare, span by value O3 long arrays
* clang - https://quick-bench.com/q/AT8Yx_JK7K7i1IntPsag1d8TKFw
* clang with libc++ - https://quick-bench.com/q/bMdOysOO262Ewci2BMjRQMAIUZw 1.1 faster!
* gcc - https://quick-bench.com/q/1XcVYjj1RUZtG7gf7h5RAUSur8M

without pivot compare, span by const ref O3 long arrays
* clang - https://quick-bench.com/q/4KJyAHo7f9hbGUUq8JX6r-oMG2Y
* gcc - https://quick-bench.com/q/7RpBwHkH2RAYecZRC5QuntpQ1Jk

* clang - calling _impl directly - https://quick-bench.com/q/X0C3OQdHw_o8YddIejgqdAtFLJw  
* gcc - matching code to clang - https://quick-bench.com/q/K04BJk3NrSYG4ViTwoTUbGyIL_w

O2 - no const calling _impl directly (clang is faster)
* clang - https://quick-bench.com/q/hh3ySEqyXD2hu6Yx0OnHv6AVbbg    
* gcc - https://quick-bench.com/q/Im74_N2rgMEpQbQOw_unMeQPDnk
* gcc - long array, with pivot - https://quick-bench.com/q/vIaSrtw89W4bqUGVzixnDwaqMZM
* clang - long array, with pivot - https://quick-bench.com/q/y2Qi_EHphbthuWXX0pfQJ-5Zey4

more consts O2 - all const calling _impl directly (gcc - same, clang - worse )
* gcc https://quick-bench.com/q/C6o-TlRfUrpEEc2nJVe3xGs8E8g  
* clang https://quick-bench.com/q/1QoopLTA8DQE-JFEDrKO9k2DaME 

same as above with O3 (without pivor compare)
* clang - https://quick-bench.com/q/4KJyAHo7f9hbGUUq8JX6r-oMG2Y    
* gcc - https://quick-bench.com/q/7RpBwHkH2RAYecZRC5QuntpQ1Jk

separate - almost the same
* gcc - geeks only https://quick-bench.com/q/jZKfw4_0hnzyHAorw9PJJmvgZRY
* gcc - sort only https://quick-bench.com/q/Autwqj7DfGkR_zoaM1WRcGWCS1o
* clang - sort only https://quick-bench.com/q/OUasLeK11DKF4i-9z8gXG3qDrpQ  
* clang - geeks only https://quick-bench.com/q/TbmXwGJxQuLZLJ7KJhaYtxkubV8  (a bit slower than sort)  

gcc - sort running before geeks
* https://quick-bench.com/q/gD8UYhGRlBOQVQBzMDE5MA741zQ 

gcc sort - remove const& from func param a bit slower. so const does help  
* https://quick-bench.com/q/v9dTmAC3ghfcdA16kWUrjZWwe9M 

Godbolt
* gcc sort https://godbolt.org/z/hxvWTz86E 
* gcc geeks https://godbolt.org/z/vsErEeb7W 
* diff https://godbolt.org/z/q7T8G3jM3  

5/22/2021 after working with Jason Turner on Discord.
* He found out that using iterator instead int for "lower" is much faster
* the const & for span is really messing up things and is slower
* clang - with all elements (fastest) - https://quick-bench.com/q/U-wfgBGsFVn7uUmBjNVZre7IK3E
* gcc - with all elements (fast) - https://quick-bench.com/q/Hqg-jpftC_acXRNMkhVyw0TUv10
* gcc - excluding pivot (still fast) - https://quick-bench.com/q/9Fw0tnbM6Etf-2NP-hb1FiP-GXc 
