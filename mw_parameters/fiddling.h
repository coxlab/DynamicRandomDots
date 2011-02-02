#include "mw_parameters.h"
#include <iostream>


namespace mw{



  class MyCustomObject : public Component, public ComponentFactory {
    
  protected:

    // -----------------------------------------------------------------------
    // This block is all that need be added to a normal object
    // in order to generate a validating factory object

    BEGIN_MW_PARAMETERS
      MW_SIGNATURE("stimulus/mystimulus")
      MW_PARAMETER(frames_per_second,   double,           60.0  );
      MW_PARAMETER(a_number,            int,              42    );
      MW_PARAMETER(a_variable,          VariablePtr,      10    );
    END_MW_PARAMETERS

    static shared_ptr<Component> createComponent(MW_PARAMETERS p){
      shared_ptr<Component> c(new MyCustomObject(p->frames_per_second,
                                                 p->a_number));
      return c;
    }   
    // -----------------------------------------------------------------------
    
    
    
    double        frames_per_second;
    int           a_number;
    VariablePtr   a_variable;

  public:  
    
    MyCustomObject(){ }
    
    MyCustomObject(double _frames_per_second, int _a_number){
      frames_per_second = _frames_per_second;
      a_number = _a_number;
    }
    
    virtual void printStuff(){          
      std::cerr << "frames_per_second = " << frames_per_second << std::endl;
      std::cerr << "a_number = " << a_number << std::endl;
    }
      
  };
    
}




