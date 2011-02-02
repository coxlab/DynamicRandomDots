/*
 *  DynamicRandomDots.h
 *  DynamicRandomDots
 *
 *  Created by Christopher Stawarz on 8/6/10.
 *  Copyright 2010 MIT. All rights reserved.
 *
 */

#ifndef DynamicRandomDots_H_
#define DynamicRandomDots_H_

#include <boost/random.hpp>
#include <MWorksCore/StandardDynamicStimulus.h>

#include "SelfDescribingComponent.h"
#include "mw_parameters.h"

using namespace mw;


class DynamicRandomDots : public StandardDynamicStimulus {

public:
    
    // -----------------------------------------------------------------------
    // This block is all that need be added to a normal object
    // in order to generate a validating factory object
    
    BEGIN_MW_PARAMETERS
    
    MW_SIGNATURE("stimulus/dynamic_random_dots");
    
    MW_PARAMETER(tag,               string,           "Dynamic Random Dots");
    MW_PARAMETER(frames_per_second, VariablePtr,      "60.");
    MW_PARAMETER(field_radius,      double,           "10.");
    MW_PARAMETER(field_center_x,    double,           "0.");
    MW_PARAMETER(field_center_y,    double,           "0.");
    MW_PARAMETER(num_dots,          int,              "100");
    MW_PARAMETER(dot_size,          double,           "1.0");
    MW_PARAMETER(color,             ColorTriple,      "1.0,1.0,1.0");
    MW_PARAMETER(alpha_multiplier,  double,           "1.0");
    MW_PARAMETER(direction,         VariablePtr,      "0");
    MW_PARAMETER(speed,             VariablePtr,      "10");
    
    END_MW_PARAMETERS
    
    static shared_ptr<Component> createComponent(MW_PARAMETERS p){
        DynamicRandomDots *dots = new DynamicRandomDots(p->tag,
                                                        p->frames_per_second,
                                                        p->field_radius,
                                                        p->field_center_x,
                                                        p->field_center_y,
                                                        p->num_dots,
                                                        p->dot_size,
                                                        p->color,
                                                        p->alpha_multiplier,
                                                        p->direction,
                                                        p->speed);
        shared_ptr<DynamicRandomDots> d(dots);
        return d;
    }   
    // Bog-standard class below this line
    // -----------------------------------------------------------------------


    DynamicRandomDots(   string         _tag,
                         VariablePtr    _frames_per_second,  
                         GLfloat        field_radius,
                         GLfloat        field_center_x,
                         GLfloat        field_center_y,
                         GLint          num_dots,
                         GLfloat        dot_size,
                         ColorTriple    color,
                         GLfloat        _alpha,
                         VariablePtr    _direction,
                         VariablePtr    _speed);

    virtual ~DynamicRandomDots();
    
    virtual void willPlay();
    virtual void didStop();
    
    virtual void load(shared_ptr<StimulusDisplay> display);
    virtual void drawFrame(shared_ptr<StimulusDisplay> display, int frameNumber);
    virtual Datum getCurrentAnnounceDrawData();
    
private:
    DynamicRandomDots(const DynamicRandomDots &tocopy);
    
    void validateParameters();
    void computeDotSizeInPixels(shared_ptr<StimulusDisplay> display);
    void initializeDots();
    void updateDots();
    
    template<typename RealType>
    RealType rand(RealType min, RealType max) {
        boost::uniform_real<RealType> randDist(min, max);
        boost::variate_generator< boost::mt19937&, boost::uniform_real<RealType> > randVar(randGen, randDist);
        return randVar();
    }
    
    GLfloat fieldRadius;
    GLfloat fieldCenterX, fieldCenterY;
    GLint numDots;
    GLfloat dotSize;
    GLfloat colorR, colorG, colorB, alpha;
    shared_ptr<Variable> direction;
    shared_ptr<Variable> speed;
    
    static const GLint verticesPerDot = 2;
    std::vector<GLfloat> dots;
    std::vector<GLfloat> dotSizeInPixels;

    boost::mt19937 randGen;
    
    MWTime previousTime, currentTime;
         

};


#endif 























