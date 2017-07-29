This code solves the following problem (that can be accessed in this brazilian online judge called The Huxley. Link: https://www.thehuxley.com/problem/102?locale=en_US):

			AUTOMATIC SAFE BOX

 An entrepreneur tired of opening the safe box from his office by turning the key disk every day, asked to a mechatronics engineer to create a small device and attached it to the safe lock, the idea is for the device to recognize a list of commands with a password and turn the safe on its own

 However, the engineer want finish this as fast as possible, so he asked you to write the program while he assembles the hardware.

 Your program should receive the values of the roulette and its initial position as starting data:

With these data your program must execute commands such as:

	D 2, turn 2 times clockwise     
	E 1, turn counterclockwise 


After each command, your program must show the roulette's values in a clockwise direction starting from the value currently pointed.


	INPUT:

The input begins with an integer N> 0 indicating the number of elements in the roulette. The next N numbers are the values contained in the roulette's slots. Where the first value is the one currently pointed by roulette.

The next lines have a character C and a positive integer value V separated by a blank space indicating respectively the command and the number of times the command is executed

Where the values of C can be:

D - Turn Right (clockwise)

E - Turn left (counterclockwise)

S - Exit

The test case ends when it receives the command "S" independently of the number that follows.


	OUTPUT:

The output must contain one line per command (except the last) containing the roulette's numbers separated by blank spaces from the starting position; there is a blank space and a line break (' ') at the end of each output line

	EXAMPLE

input:

7
20
12
22
7
30
40
50
D 2
E 1
S 1

output:

40 50 20 12 22 7 30 
50 20 12 22 7 30 40 



