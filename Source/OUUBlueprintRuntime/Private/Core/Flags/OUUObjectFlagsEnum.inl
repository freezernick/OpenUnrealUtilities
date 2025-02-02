﻿// Copyright (c) 2022 Jonas Reich

#ifndef OUU_DECLARE_OBJECT_FLAGS
COMPILE_ERROR("OUU_DECLARE_OBJECT_FLAGS was not defined. Please do not include this file outside of OUUBlueprintObjectFlags.cpp");
#endif

OUU_DECLARE_OBJECT_FLAGS(NoFlags),
OUU_DECLARE_OBJECT_FLAGS(Public),
OUU_DECLARE_OBJECT_FLAGS(Standalone),
OUU_DECLARE_OBJECT_FLAGS(MarkAsNative),
OUU_DECLARE_OBJECT_FLAGS(Transactional),
OUU_DECLARE_OBJECT_FLAGS(ClassDefaultObject),
OUU_DECLARE_OBJECT_FLAGS(ArchetypeObject),
OUU_DECLARE_OBJECT_FLAGS(Transient),
OUU_DECLARE_OBJECT_FLAGS(MarkAsRootSet),
OUU_DECLARE_OBJECT_FLAGS(TagGarbageTemp),
OUU_DECLARE_OBJECT_FLAGS(NeedInitialization),
OUU_DECLARE_OBJECT_FLAGS(NeedLoad),
OUU_DECLARE_OBJECT_FLAGS(KeepForCooker),
OUU_DECLARE_OBJECT_FLAGS(NeedPostLoad),
OUU_DECLARE_OBJECT_FLAGS(NeedPostLoadSubobjects),
OUU_DECLARE_OBJECT_FLAGS(NewerVersionExists),
OUU_DECLARE_OBJECT_FLAGS(BeginDestroyed),
OUU_DECLARE_OBJECT_FLAGS(FinishDestroyed),
OUU_DECLARE_OBJECT_FLAGS(BeingRegenerated),
OUU_DECLARE_OBJECT_FLAGS(DefaultSubObject),
OUU_DECLARE_OBJECT_FLAGS(WasLoaded),
OUU_DECLARE_OBJECT_FLAGS(TextExportTransient),
OUU_DECLARE_OBJECT_FLAGS(LoadCompleted),
OUU_DECLARE_OBJECT_FLAGS(InheritableComponentTemplate),
OUU_DECLARE_OBJECT_FLAGS(DuplicateTransient),
OUU_DECLARE_OBJECT_FLAGS(StrongRefOnFrame),
OUU_DECLARE_OBJECT_FLAGS(NonPIEDuplicateTransient),
OUU_DECLARE_OBJECT_FLAGS(WillBeLoaded),
OUU_DECLARE_OBJECT_FLAGS(HasExternalPackage),
OUU_DECLARE_OBJECT_FLAGS(AllocatedInSharedPage),
OUU_DECLARE_OBJECT_FLAGS(AllFlags),
OUU_DECLARE_OBJECT_FLAGS(Load),
OUU_DECLARE_OBJECT_FLAGS(PropagateToSubObjects)
