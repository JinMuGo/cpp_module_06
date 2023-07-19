/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 16:15:46 by jgo               #+#    #+#             */
/*   Updated: 2023/07/19 17:01:11 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "Base.hpp"
#include "C.hpp"
#include <cstdlib>
#include <typeinfo>

Base::t_abc my_random(const int max) {
	static bool flag = false;

	if (flag == false) {
		srand(time(NULL));
		flag = true;
	}
	return (static_cast<Base::t_abc>(rand() % max));
}

Base* generate(void) {
	const Base::t_abc abc = my_random(3);
	switch (abc) {
		case Base::A:
			return (new A);
		case Base::B:
			return (new B);
		case Base::C:
			return (new C);
	}
	return (new A);
}

// https://blockdmask.tistory.com/241
// https://stackoverflow.com/questions/351845/finding-the-type-of-an-object-in-c
void identify(Base* p) {
	if (dynamic_cast<A*>(p))
		std::cout << RED "the pointer type is A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << YELLOW "the pointer type is B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << GREEN "the pointer type is C" << std::endl;
}

void identify(Base& p) {
	try {
		A a = dynamic_cast<A&>(p);
		std::cout << RED "the reference type is A" << std::endl;
	} catch (const std::bad_cast& e) {
		std::cerr << e.what() << '\n';
	}
	try {
		B b = dynamic_cast<B&>(p);
		std::cout << YELLOW "the reference type is B" << std::endl;
	} catch (const std::bad_cast& e) {
		std::cerr << e.what() << '\n';
	}
	try {
		C c = dynamic_cast<C&>(p);
		std::cout << GREEN "the reference type is C" << std::endl;
	} catch (const std::bad_cast& e) {
		std::cerr << e.what() << '\n';
	}
}

int main(void) {
	Base* ptr = generate();
	Base* ptr2 = generate();

	identify(ptr);
	identify(*ptr);
	identify(ptr2);
	identify(*ptr2);

	delete ptr;
	delete ptr2;

	//system("leaks Identify_real_type");
	return (0);
}
