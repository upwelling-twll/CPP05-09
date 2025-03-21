#include "Serializer.hpp"
#include "Data.hpp"

int main()
{
	Data*		ptr = NULL;
	uintptr_t	data;
	Data*		againPtr;

	ptr->horseName = "Spirit";
	ptr->birthDate = 20200101;
	ptr->breed = "Arabian";

	data = Serializer::serialize(ptr);
	againPtr = Serializer::deserialize(data);
	std::cout << againPtr->horseName << std::endl;
}
