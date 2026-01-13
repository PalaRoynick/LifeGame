The Life Game program written in modern C++.
See https://gameoflifeworld.com/?ysclid=mkcb7f9lcp30572315%2F/ for details.

Here I describe some ideas which followed me during the work
at the project.

0. Project Structure.
First attempt included types design, multithreaded support, tests.
It took around 1.5 hour.

1. Started working on basic inputs and Cell class
It took around 1.5 hour. Used std::format, std::ranges::views::cartesian_product,

2. Added basic functionality, checked some basic tests, all passed.
Classes: StateMachine, CellBoard.
For now some dummy visual output to terminal.
Overall took around 3 h, managing dependenices b/n StateMachine's components.