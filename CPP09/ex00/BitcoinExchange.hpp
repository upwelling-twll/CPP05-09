#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <map>

class BitcoinExchange
{
private:
	std::map<std::string, float> _dataBase; //map<date, value>

public:
	/*Member functions*/
    void parseDataBase(char *file);
	bool validateDataBase();
	bool validateDBLine(std::string line);
	void multiplyValue(std::string date, float value);

	/*Getters and Setters*/
	std::map<std::string, float> getDataBase() const;

	/*Constructors*/
    BitcoinExchange();
	BitcoinExchange(void);

	/*Destructors*/
    ~BitcoinExchange( void );

	/*Overload operators*/
	BitcoinExchange &operator=(const BitcoinExchange& src);
};

std::ostream& operator<<(std::ostream &output_stream, BitcoinExchange& src);

#endif // BITCOINEXCHANGE_HPP
