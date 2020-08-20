
#include <avr/io.h>
#define F_CPU 1000000UL
#include <util/delay.h>

uint32_t binNum = 998;
uint16_t bin_to_bcd(uint32_t inVal);
uint16_t b = 11;
int main(void)
{
	b = bin_to_bcd(binNum);
	DDRB = 1;
	PORTB = 1;
		
    while (1) 
    {
		
		_delay_ms(500);
    }
}

uint16_t bin_to_bcd(uint32_t inVal)
{
	for(int i = 0; i < 7; i++)
	{
		inVal = inVal << 1;
		
		if (((inVal >> 8) & 0x0000000F)  > 4)
		{
			inVal += 768;
		}
		if (((inVal >> 12)  & 0x0000000F) > 4)
		{
			inVal += 12288;
		}	
	}
	int16_t outVal = inVal >> 7;
	return outVal;
}