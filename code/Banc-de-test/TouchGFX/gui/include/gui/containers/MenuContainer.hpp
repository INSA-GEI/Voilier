#ifndef MENUCONTAINER_HPP
#define MENUCONTAINER_HPP

#include <gui_generated/containers/MenuContainerBase.hpp>
#include <BitmapDatabase.hpp>

class MenuContainer : public MenuContainerBase
{
public:
	MenuContainer();
	virtual ~MenuContainer() {}

	virtual void initialize();

	void setNumber(int no)
	{
		switch (no)
		{
		case 0:
			image.setBitmap(Bitmap(BITMAP_ICONS8_COMPASS_48_ID));
			Unicode::snprintf(textAreaBuffer, TEXTAREA_SIZE, "Orientation\nPlateau");
			break;
		case 1:
			image.setBitmap(Bitmap(BITMAP_ICONS8_WIND_48_ID));

			Unicode::snprintf(textAreaBuffer, TEXTAREA_SIZE, "Orientation\nVoile");
			break;
		case 2:
			image.setBitmap(Bitmap(BITMAP_ICONS8_SAMPLE_RATE_48_ID));
			Unicode::snprintf(textAreaBuffer, TEXTAREA_SIZE, "Tension\nBatterie");
			break;
		case 3:
			image.setBitmap(Bitmap(BITMAP_COMMUNICATION_48_ID));
			Unicode::snprintf(textAreaBuffer, TEXTAREA_SIZE, "Com\nSerie");
			break;
		case 4:
			image.setBitmap(Bitmap(BITMAP_I2C_SPI_48_ID));
			Unicode::snprintf(textAreaBuffer, TEXTAREA_SIZE, "Com\nI2C & SPI");
			break;
		case 5:
			image.setBitmap(Bitmap(BITMAP_GIROUTTE_48_ID));
			Unicode::snprintf(textAreaBuffer, TEXTAREA_SIZE, "Girouette");
			break;
		case 6:
			image.setBitmap(Bitmap(BITMAP_ICONS8_TEST_PASSED_48_ID));
			Unicode::snprintf(textAreaBuffer, TEXTAREA_SIZE, "Test\nComplet");
			break;
		default:
			break;
		}
	}

protected:
};

#endif // MENUCONTAINER_HPP
