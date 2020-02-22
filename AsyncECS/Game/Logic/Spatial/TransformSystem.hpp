//
//  TransformSystem.hpp
//  AsyncECS
//
//  Created by Jeppe Nielsen on 19/02/2020.
//  Copyright © 2020 Jeppe Nielsen. All rights reserved.
//

#pragma once
#include "Scene.hpp"
#include "Parent.hpp"
#include "LocalTransform.hpp"
#include "WorldTransform.hpp"
#include "DirtyTransform.hpp"

namespace Game {
    struct TransformSystem :
        AsyncECS::SystemChanged<const LocalTransform, const Parent, const DirtyTransform, WorldTransform>,
        AsyncECS::NoSystemDependencies,
        AsyncECS::ComponentView<const LocalTransform, const Parent, const DirtyTransform, WorldTransform> {
        
        void Initialize();
        void Changed(const LocalTransform& localTransform, const Parent& parent, const DirtyTransform& dirtyTransform, WorldTransform& worldTransform);
        
        void Update(const LocalTransform& localTransform, const Parent& parent, const DirtyTransform& dirtyTransform, WorldTransform& worldTransform);
    
    };
}
