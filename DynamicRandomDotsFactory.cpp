/*
 *  DynamicRandomDotsFactory.cpp
 *  DynamicRandomDots
 *
 *  Created by Christopher Stawarz on 8/6/10.
 *  Copyright 2010 MIT. All rights reserved.
 *
 */

#include <MWorksCore/ComponentRegistry.h>
#include <MWorksCore/ParsedColorTrio.h>

#include "DynamicRandomDotsFactory.h"
#include "DynamicRandomDots.h"

using namespace mw;


shared_ptr<mw::Component> DynamicRandomDotsFactory::createObject(std::map<std::string, std::string> parameters,
                                                                 ComponentRegistry *reg)
{
    const char* TAG = "tag";
    const char* FRAMES_PER_SECOND = "frames_per_second";
    const char* FIELD_RADIUS = "field_radius";
    const char* FIELD_CENTER_X = "field_center_x";
    const char* FIELD_CENTER_Y = "field_center_y";
    const char* NUM_DOTS = "num_dots";
    const char* DOT_SIZE = "dot_size";
    const char* COLOR = "color";
    const char* ALPHA_MULTIPLIER = "alpha_multiplier";
    const char* DIRECTION = "direction";
    const char* SPEED = "speed";

	REQUIRE_ATTRIBUTES(parameters, 
					   TAG,
                       FRAMES_PER_SECOND,
                       FIELD_RADIUS,
                       FIELD_CENTER_X,
                       FIELD_CENTER_Y,
                       NUM_DOTS,
                       DOT_SIZE,
                       COLOR,
                       ALPHA_MULTIPLIER,
                       DIRECTION,
                       SPEED);
	
	std::string tag(parameters[TAG]);
    
	shared_ptr<Variable> framesPerSecond(reg->getVariable(parameters[FRAMES_PER_SECOND]));
	CHECK_ATTRIBUTE(framesPerSecond, parameters, FRAMES_PER_SECOND);
    
	shared_ptr<Variable> fieldRadius(reg->getVariable(parameters[FIELD_RADIUS]));
	CHECK_ATTRIBUTE(fieldRadius, parameters, FIELD_RADIUS);
    
	shared_ptr<Variable> fieldCenterX(reg->getVariable(parameters[FIELD_CENTER_X]));
	CHECK_ATTRIBUTE(fieldCenterX, parameters, FIELD_CENTER_X);
    
	shared_ptr<Variable> fieldCenterY(reg->getVariable(parameters[FIELD_CENTER_Y]));
	CHECK_ATTRIBUTE(fieldCenterY, parameters, FIELD_CENTER_Y);
    
	shared_ptr<Variable> numDots(reg->getVariable(parameters[NUM_DOTS]));
	CHECK_ATTRIBUTE(numDots, parameters, NUM_DOTS);
    
	shared_ptr<Variable> dotSize(reg->getVariable(parameters[DOT_SIZE]));
	CHECK_ATTRIBUTE(dotSize, parameters, DOT_SIZE);
    
	ParsedColorTrio pct(reg, parameters[COLOR]);
    
	shared_ptr<Variable> alphaMultiplier(reg->getVariable(parameters[ALPHA_MULTIPLIER]));
	CHECK_ATTRIBUTE(alphaMultiplier, parameters, ALPHA_MULTIPLIER);
    
	shared_ptr<Variable> direction(reg->getVariable(parameters[DIRECTION]));
	CHECK_ATTRIBUTE(direction, parameters, DIRECTION);
    
	shared_ptr<Variable> speed(reg->getVariable(parameters[SPEED]));
	CHECK_ATTRIBUTE(speed, parameters, SPEED);
	
	shared_ptr<DynamicRandomDots> newComponent(new DynamicRandomDots(tag,
                                                                     framesPerSecond,
                                                                     fieldRadius,
                                                                     fieldCenterX,
                                                                     fieldCenterY,
                                                                     numDots,
                                                                     dotSize,
                                                                     pct.getR(),
                                                                     pct.getG(),
                                                                     pct.getB(),
                                                                     alphaMultiplier,
                                                                     direction,
                                                                     speed));

    newComponent->load(StimulusDisplay::getCurrentStimulusDisplay());
	shared_ptr<StimulusNode> node(new StimulusNode(newComponent));
	reg->registerStimulusNode(tag, node);
	
	return newComponent;
}






















