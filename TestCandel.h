#pragma once
#include <vector>
#include <functional>
#include <iostream>
#include <string>

class TestCandel {
public:
	using type_vtest = std::vector<std::function<bool()>>;
	using ctype_vtest = const std::vector<std::function<bool()>>;
	using type_vtest_reference = std::vector<std::function<bool()>>&;
	using ctype_vtest_reference = const std::vector<std::function<bool()>>&;

	TestCandel(void) = default;
	~TestCandel() = default;


	void initTests(ctype_vtest_reference newTests) {
		_tests.insert(_tests.end(), newTests.begin(), newTests.end());
	}

	int launchTests() {
		total = 0;
		passed = 0;
		failed = 0;

		for (const auto& test : _tests) {
			std::cout << "Test #" << (total + 1);
			if (test())
			{
				passed++;
				std::cout << " passed." << std::endl;
			}
			else
			{
				failed++;
				std::cout << " failed." << std::endl;
			}
			total += 1;
		}
		std::cout << "\nTotal test #" + std::to_string(total) << std::endl;
		std::cout << "Total passed #" + std::to_string(passed) << std::endl;
		std::cout << "Total failed #" + std::to_string(failed) << std::endl;

		std::cout << "\nTests: " + std::to_string(passed) + "/" + std::to_string(total) + " passed!" << std::endl;


		return failed;
	}

private:
	type_vtest _tests;
	unsigned total = 0;
	unsigned passed = 0;
	unsigned failed = 0;
};