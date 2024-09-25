#include <gui/screen1_screen/Screen1View.hpp>

#include "update_data.h"

Screen1View::Screen1View()
{

}

void Screen1View::setupScreen()
{
    Screen1ViewBase::setupScreen();
}

void Screen1View::tearDownScreen()
{
    Screen1ViewBase::tearDownScreen();
}

void Screen1View::handleTickEvent()
{
  static MeasuredDataTypeDef DataToDisp;
  
  DataToDisp = getData();
  if(DataToDisp.new_data_flag){
      float temp_to_disp = DataToDisp.temp;
      temp_to_disp = temp_to_disp/100;
      temp_graph.addDataPoint(temp_to_disp);
      Unicode::snprintfFloat(temp_textBuffer, TEMP_TEXT_SIZE, "%f", temp_to_disp);
      temp_text.invalidate();

      lux_graph.addDataPoint(DataToDisp.lux);
      Unicode::snprintf(lux_textBuffer, LUX_TEXT_SIZE, "%d", DataToDisp.lux);
      lux_text.invalidate();  
      
      DataToDisp.new_data_flag = 0;
  }
}