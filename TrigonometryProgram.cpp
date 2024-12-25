#include <iostream>
#include <cmath>
#define PI 3.141592654

int main() {
	double a;			// The A side of a triangle -- Will be used for the adjacent value
	double b;			// The B side of a triangle -- Will be used for the opposite value
	double c;			// The C side of a triangle -- Will be used for the hypotenuse value
	double degree;			// The degree of a specific point in a triangle
	char choice1;			// Choose which theorem to calculate
	char choice2;			// Choose a side of a triangle
	char choice3;			// Choose whether to calculate the angle or a side of a triangle (sine, cosine, and tangent exclusive)

	std::cout << "**************************************** TRIGONOMETRY PROGRAM ****************************************\n";
	std::cout << "\nPlease choose which theorem you'd like to calculate (Pythagoras theorem, sine, cosine, tangent): ";
	std::cin >> choice1;
	choice1 = tolower(choice1); // Converts whatever the user entered into a lowercase (makes it easier for me lol)

	switch (choice1) {
	case 'p':																			// Pythagoras theorem
		std::cout << "\nWhich side are you looking to find? (A, B, C): ";
		std::cin >> choice2;
		choice2 = tolower(choice2);

		while (choice2 != 'a' && choice2 != 'b' && choice2 != 'c') {					// If the user inputted an incorrect value
			std::cout << "\nValue invalid. Please try again.";
			std::cout << "\nWhich side are you looking to find? (A, B, C): ";
			std::cin >> choice2;
			choice2 = tolower(choice2);
		}

		switch (choice2) {
		case 'a':																		// Calculate the value of side A
			std::cout << "\nWhat's the value of B?: ";
			std::cin >> b;

			while (b <= 0) {
				std::cout << "Value invalid. Please try again.\n";
				std::cout << "\nWhat's the value of B?: ";
				std::cin >> b;
			}

			std::cout << "\nWhat's the value of C?: ";
			std::cin >> c;

			while (c <= 0 || c <= b) {
				std::cout << "Value invalid. Please try again.\n";
				std::cout << "\nWhat's the value of C?: ";
				std::cin >> c;
			}

			a = sqrt(c * c - b * b);													// Formula for calculating the value of side A

			std::cout << "Side A is equal to " << a << "cm.\n";
			break;

		case 'b':
			std::cout << "\nWhat's the value of A?: ";
			std::cin >> a;

			while (a <= 0) {
				std::cout << "Value invalid. Please try again.\n";
				std::cout << "\nWhat's the value of A?: ";
				std::cin >> a;
			}

			std::cout << "\nWhat's the value of C?: ";
			std::cin >> c;

			while (c <= 0 || c <= a) {
				std::cout << "Value invalid. Please try again.\n";
				std::cout << "\nWhat's the value of C?: ";
				std::cin >> c;
			}

			b = sqrt(c * c - a * a);

			std::cout << "Side B is equal to " << b << "cm.\n";
			break;
		case 'c':
			std::cout << "\nWhat's the value of A?: ";
			std::cin >> a;

			while (a <= 0) {
				std::cout << "Value invalid. Please try again.\n";
				std::cout << "\nWhat's the value of A?: ";
				std::cin >> a;
			}

			std::cout << "\nWhat's the value of B?: ";
			std::cin >> b;

			while (b <= 0) {
				std::cout << "Value invalid. Please try again.\n";
				std::cout << "\nWhat's the value of B?: ";
				std::cin >> b;
			}

			c = sqrt(a * a + b * b);

			std::cout << "Side C is equal to " << c << ".\n";
			break;
		}
		break;
	case 's':

		std::cout << "\nAre you calculating the unknown value or the angle? (V or A): ";
		std::cin >> choice3;
		choice3 = tolower(choice3);

		while (choice3 != 'v' && choice3 != 'a') {
			std::cout << "\nValue invalid. Please try again.";
			std::cout << "\nAre you calculating the unknown value or the angle? (V or A): ";
			std::cin >> choice3;
			choice3 = tolower(choice3);
		}

		switch (choice3) {
		case 'v':
			std::cout << "\nWhich value is known, A (opposite) or C (hypotenuse)?: ";
			std::cin >> choice2;
			choice2 = tolower(choice2);

			while (choice2 != 'a' && choice2 != 'c') {
				std::cout << "\nValue invalid. Please try again.";
				std::cout << "\nWhich value is known, A (opposite) or C (hypotenuse)?: ";
				std::cin >> choice2;
				choice2 = tolower(choice2);
			}

			switch (choice2) {
			case 'a':
				std::cout << "\nWhat is the value of A?: ";
				std::cin >> a;

				while (a <= 0) {
					std::cout << "\nValue invalid. Please try again.";
					std::cout << "\nWhat is the value of A?: ";
					std::cin >> a;
				}

				std::cout << "\nWhat's the value of the angle? Must be less than 90 degrees: ";
				std::cin >> degree;

				while (degree <= 0 || degree >= 90) {
					std::cout << "\nValue invalid. Please try again.";
					std::cout << "\nWhat's the value of the angle? Must be less than 90 degrees: ";
					std::cin >> degree;
				}

				c = a / sin(degree);

				std::cout << "\nThe value of C is " << c << ".";
				break;

			case 'c':
				std::cout << "\nWhat's the value of C?: ";
				std::cin >> c;

				std::cout << "\nWhat's the value of the angle? Must be less than 90 degrees: ";
				std::cin >> degree;

				a = c * sin(degree);

				std::cout << "\nThe value of A is " << a << ".";
				break;
			default:
				std::cout << "\nWait, how did you get here?";												// This shouldn't happen...
				break;
			}
			break;
		case 'a':
			std::cout << "\nWhat's the value of A (opposite)?: ";
			std::cin >> a;

			std::cout << "\nWhat's the value of C (hypotenuse)?: ";
			std::cin >> c;

			while (c <= a) {
				std::cout << "\nValue invalid. Please try again.";
				std::cout << "\nWhat's the value of C (hypotenuse)?: ";
				std::cin >> c;
			}

			degree = asin(a / c) * 180 / PI;

			std::cout << "\nThe degree in this right angle triangle is " << degree << " degrees.";
			break;
		default:
			std::cout << "\nWanna know something? This was made by an 18 year old bisexual furry.";			// This also shouldn't happen...
			break;
		}
		break;

	case 'c':
		std::cout << "\nAre you calculating the unknown value or the angle? (V or A): ";
		std::cin >> choice3;
		choice3 = tolower(choice3);


		switch (choice3) {
		case 'v':
			std::cout << "\nWhich value is known, B (adjacent) or C (hypotenuse)?: ";
			std::cin >> choice2;
			choice2 = tolower(choice2);

			switch (choice2) {
			case 'b':
				std::cout << "\nWhat's the value of B?: ";
				std::cin >> b;

				std::cout << "\nWhat's the value of the angle? Must be less than 90 degrees: ";
				std::cin >> degree;

				c = b / cos(degree);

				std::cout << "\nThe value of C is " << c << ".";
				break;
			case 'c':
				std::cout << "\nWhat's the value of C?: ";
				std::cin >> c;

				std::cout << "\nWhat's the value of the angle? Must be less than 90 degrees: ";
				std::cin >> degree;

				b = c * cos(degree);

				std::cout << "\nThe value of B is " << b << ".";
				break;
			}
			break;
		case 'a':
			std::cout << "\nWhat's the value of B (adjacent)?: ";
			std::cin >> b;

			std::cout << "\nWhat's the value of C (hypotenuse)?: ";
			std::cin >> c;

			degree = acos(b / c) * 180 / PI;

			std::cout << "\nThe degree in this right triangle is " << degree << " degrees.";
			break;
		default:
			std::cout << "\nUwU";
			break;
		}
		break;

	case 't':
		std::cout << "\nAre you calculating the unknown value or the angle? (V or A): ";
		std::cin >> choice3;
		choice3 = tolower(choice3);

		switch (choice3) {
		case 'v':
			std::cout << "\nWhich value is known, A (opposite) or B (adjacent)?: ";
			std::cin >> choice2;
			choice2 = tolower(choice2);

			switch (choice2) {
			case 'a':
				std::cout << "\nEnter the value of A: ";
				std::cin >> a;

				std::cout << "\nWhat's the value of the angle? Must be less than 90 degrees: ";
				std::cin >> degree;

				b = a / tan(degree);

				std::cout << "\nThe value of B is " << b << ".";
				break;
			case 'b':
				std::cout << "\nEnter the value of B: ";
				std::cin >> b;

				std::cout << "\nWhat's the value of the angle? Must be less than 90 degrees: ";
				std::cin >> degree;

				a = b * tan(degree);

				std::cout << "\nThe value of A is " << a << ".";
				break;
			default:
				std::cout << "\nIntruder alert! A red spy is in the base! A red spy is in the base? Hut hut hut hut. Protect the briefcase! We need to protect the briefcase! Yo, a little help here! Alright, alright I got it. Stand back son. 1, 1, 1, um... 1. Let's go, let's go, let's go. Incoming! Hey it's still here. Alright then. Ahem, gentlemen. I see the briefcase is safe. Safe and sound. Yeah, it is. Tell me, did anyone happen to kill a red spy on the way here? No? Then we still have a problem. And a knife. Ooh, big problem. I've killed plenty of spies. The dime-a-dozen backstabbing scumbags, like you. Ow! No offense. If you manage to kill them, I assure you they were not like me. And nothing, nothing like the man loose inside this building. What, are you president of his fan club? No. That would be your mother. What the? Wait...? Indeed, and now he's here to f**k us! So listen up boy, or pornography starring your mother will be the second worst thing to happen to you today. Oh! Give me that! This spy has already breached our defenses. Sentry down! You've seen what he's done to our colleagues! And worst of all, it could be any one of us. It could be in this very room. It could be you. It could be me. It could even be-- Woah, woah, woah! Woah. What? It was obvious. He's the red spy. Watch, he'll turn red any second now. Any second now. See! Red! No wait, that's blood. So, we still got problem. Big problem. Alright, who's ready to go find this spy? Right behind you. Oh? Ah, ma petite chou fleur.";
				break;
			}
			break;
		case 'a':
			std::cout << "\nWhat's the value of A (opposite)?: ";
			std::cin >> a;

			std::cout << "\nWhat's the value of B (adjacent)?: ";
			std::cin >> b;

			degree = atan(a / b) * 180 / PI;

			std::cout << "\nThe degree in this right triangle is " << degree << " degrees.";
			break;
		default:
			std::cout << "\nHey all, Scott here, and this is bad! Real bad!";
			break;
		}
		break;

	default:
		std::cout << "ERROR: " << choice1 << " is not valid! Exiting...\n";
		break;
	}

	std::cout << "\n******************************************* END OF PROGRAM *******************************************\n";
	system("pause");
}
