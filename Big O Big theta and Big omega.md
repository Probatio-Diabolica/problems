# Big O                     { Upper Bound != Worst Case or any other Case}
<!-- 
    !! Big O notation represents the upper bound on the time complexity of an algorithm. It describes the worst-case scenario for the algorithm.

    -> If an algorithm has a time complexity of O(f(n)), it means that the running time of the algorithm is, at most, proportional to f(n) for all input sizes n.

    // For example, if an algorithm has a time complexity of O(n^2), it means that the algorithm's running time will not exceed a quadratic function of the input size, even in the worst case.> 
    
 -->



# Big Theta                 { Tight Bound != Expected case or any other case}
<!-- 
    !! Big Theta notation represents a tight bound on the time complexity of an algorithm. It describes both the upper and lower limits of the running time.

    -> If an algorithm has a time complexity of Θ(f(n)), it means that the running time is proportional to f(n), and it provides a precise characterization of the algorithm's performance.
    
    // For example, if an algorithm has a time complexity of Θ(n), it means that the running time grows linearly with the input size, and this bound is both a lower and upper limit.
 -->




# Big Omega                 {Lower bound != Best Case or any other case}
<!-- 
    !!  Big Omega notation represents the lower bound on the time complexity of an algorithm. It describes the best-case scenario for the algorithm.
    
    ->  If an algorithm has a time complexity of Ω(f(n)), it means that the running time is, at least, proportional to f(n) for all input sizes.
    
    //For example, if an algorithm has a time complexity of Ω(n), it means that the algorithm's running time will grow at least linearly with the input size in the best case.
 -->


<!-- 
-------------------------------------------------------------------------------------------------------------------------------------
*   In summary, Big O provides an upper bound on an algorithm's time complexity, Big Theta gives both upper and lower bounds, and Big Omega gives a lower bound. These notations help in characterizing the performance of algorithms and are used to make informed choices when selecting algorithms for specific tasks or analyzing their efficiency in various scenarios.

Note: Industry mainly uses big O, because it offers the tighest description of an angorithm's runtime.
 -->