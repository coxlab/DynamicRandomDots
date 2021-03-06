/*
 *  DynamicRandomDotsPlugin.cpp
 *  DynamicRandomDots
 *
 *  Created by Christopher Stawarz on 8/6/10.
 *  Copyright 2010 MIT. All rights reserved.
 *
 */

#include <MWorksCore/ComponentFactory.h>

#include "DynamicRandomDotsPlugin.h"
#include "DynamicRandomDotsFactory.h"

using namespace mw;


Plugin* getPlugin() {
    return new DynamicRandomDotsPlugin();
}


void DynamicRandomDotsPlugin::registerComponents(shared_ptr<ComponentRegistry> registry) {
    registry->registerFactory(std::string("stimulus/dynamic_random_dots"),
							  (ComponentFactory *)(new DynamicRandomDotsFactory()));
}
