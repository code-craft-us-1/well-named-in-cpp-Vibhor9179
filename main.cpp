#include <iostream>
#include <assert.h>
#include "ColorPair.h"
namespace TelCoColorCoder
{
    void testNumberToPair(int pairNumber,
        TelCoColorCoder::MajorColor expectedMajor,
        TelCoColorCoder::MinorColor expectedMinor)
    {
        TelCoColorCoder::ColorPair colorPair =
            TelCoColorCoder::GetColorFromPairNumber(pairNumber);
        std::cout << "Got pair " << colorPair.ToString() << std::endl;
        assert(colorPair.getMajor() == expectedMajor);
        assert(colorPair.getMinor() == expectedMinor);
    }
 
    void testPairToNumber(
        TelCoColorCoder::MajorColor major,
        TelCoColorCoder::MinorColor minor,
        int expectedPairNumber)
    {
        int pairNumber = TelCoColorCoder::GetPairNumberFromColor(major, minor);
        std::cout << "Got pair number " << pairNumber << std::endl;
        assert(pairNumber == expectedPairNumber);
    }

    std::string ColorCoding()
    {
        std::string colorCodingMessage = "The Color Coding is: \n"; 
        for(int i=1; i <= 25; i++)
        {
            ColorPair colorPair = GetColorFromPairNumber(i);
            colorCodingMessage = colorCodingMessage + std::to_string(i) + " " + colorPair.ToString() + "\n";
        }
        return colorCodingMessage;
    }
}
 
    int main() {
        testNumberToPair(4, TelCoColorCoder::WHITE, TelCoColorCoder::BROWN);
        testNumberToPair(5, TelCoColorCoder::WHITE, TelCoColorCoder::SLATE);
 
        testPairToNumber(TelCoColorCoder::BLACK, TelCoColorCoder::ORANGE, 12);
        testPairToNumber(TelCoColorCoder::VIOLET, TelCoColorCoder::SLATE, 25);

        std::cout<< TelCoColorCoder::ColorCoding();
        return 0;
    }