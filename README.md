# dijkstra
Dijkstra algorithm implemented in c++ using linked lists
[Dijstra algorithm](https://algs4.cs.princeton.edu/44sp/)

# Configuration
[How to configure VSCode c++](https://code.visualstudio.com/docs/languages/cpp)
[C++ Development using Visual Studio Code, CMake and LLDB](https://medium.com/audelabs/c-development-using-visual-studio-code-cmake-and-lldb-d0f13d38c563)

# Run
`.\dijkstra.exe -g notes/graf.txt`

# Example
`notes/graf.txt`

Path from 2 to 3 with weight 43.05

2 -> 5 : 34.65

5 -> 3 : 8.4

Path from 2 to 5 with weight 34.65

2 -> 5 : 34.65

Path from 2 to 12 with weight 52.05

2 -> 5 : 34.65

5 -> 3 : 8.4

3 -> 12 : 9

Path from 3 to 2 with weight 54.5

3 -> 2 : 54.5

Path from 3 to 5 with weight 39

3 -> 12 : 9

12 -> 5 : 30

Path from 3 to 12 with weight 9

3 -> 12 : 9

Path from 5 to 2 with weight 62.9

5 -> 3 : 8.4

3 -> 2 : 54.5

Path from 5 to 3 with weight 8.4

5 -> 3 : 8.4

Path from 5 to 12 with weight 17.4

5 -> 3 : 8.4

3 -> 12 : 9

Path from 12 to 2 with weight 59

12 -> 3 : 4.5

3 -> 2 : 54.5

Path from 12 to 3 with weight 4.5

12 -> 3 : 4.5

Path from 12 to 5 with weight 30

12 -> 5 : 30
