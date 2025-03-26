#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal
{
private:
    const std::string	specie;
	int					age;
	const int			size;

public:
	/*Member functions*/

	/*Getters and Setters*/
	const std::string getSpecie() const;
	int getAge() const;
	int getSize() const;


	/*Constructors*/
    Animal(std::string specie, int age, int size);
	Animal(void);

	/*Destructors*/
    ~Animal( void );

	/*Overload operators*/
	Animal &operator=(const Animal& src);
	bool operator<(const Animal& other) const;
	bool operator>(const Animal& other) const;
};

std::ostream& operator<<(std::ostream &output_stream, const Animal& src);

#endif // Animal_HPP
