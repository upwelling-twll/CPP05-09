#include "Serializer.hpp"
#include "Data.hpp"

int main()
{
	Data		ptr;
	// uintptr_t	data;
	Data*	againPtr;

	ptr.horseName = "Spirit";
	ptr.birthDate = 20200101;
	ptr.breed = "Arabian";
	// data = Serializer::serialize(&ptr);
	againPtr = Serializer::deserialize(Serializer::serialize(&ptr));
	std::cout << againPtr->horseName << std::endl;
	std::cout << againPtr->birthDate << std::endl;
	std::cout << againPtr->breed << std::endl;
}
