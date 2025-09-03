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
	
	std::cout << ptr.horseName << std::endl;
	std::cout << ptr.birthDate << std::endl;
	std::cout << ptr.breed << '\n' << std::endl;
	
		// data = Serializer::serialize(&ptr);
	againPtr = Serializer::deserialize(Serializer::serialize(&ptr));
	
	std::cout << '\n' << againPtr->horseName << std::endl;
	std::cout << againPtr->birthDate << std::endl;
	std::cout << againPtr->breed << std::endl;


	// std::cout << Serializer::serialize(&ptr) << std::endl;

	// int i = 5;
	// int* pi = &i;
	// // double d;
	// std::cout << reinterpret_cast<char>(pi) << std::endl;

	// uintptr_t uni = 140732722939705;
	// std::cout << reinterpret_cast<Data*>(uni) << std::endl;
	// Data* newData;
	// newData = reinterpret_cast<Data*>(uni);
	// std::cout << newData->horseName << std::endl;

}
