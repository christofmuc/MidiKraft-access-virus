/*
   Copyright (c) 2020 Christof Ruch. All rights reserved.

   Dual licensed: Distributed under Affero GPL license by default, an MIT license is available for purchase
*/

#pragma once

#include "Patch.h"
#include "StoredTagCapability.h"
#include "StoredPatchNameCapability.h"
#include "StoredPatchNumberCapability.h"

namespace midikraft {

	class VirusPatch : public DataFile, public StoredPatchNameCapability, public StoredPatchNumberCapability, public DefaultNameCapability, public StoredTagCapability {
	public:
		VirusPatch(Synth::PatchData const &data);

		// StoredPatchNameCapability
		virtual std::string name() const override;
		virtual void setName(std::string const &name) override;

		// StoredPatchNumberCapability
		virtual bool hasStoredPatchNumber() const override;
		virtual MidiProgramNumber getStoredPatchNumber() const override;
		virtual void setStoredPatchNumber(MidiProgramNumber newNumber) const override;

		// DefaultNameCapability
		virtual bool isDefaultName(std::string const &patchName) const override;

		// StoredTagCapability
		int getNumTagsStored() const override;
		bool setTags(std::set<Tag> const &tags) override;
		std::set<Tag> tags() const override;

		enum DataFileTypes { PATCH_VIRUS_B = 0 };
		enum Page { PageA = 0, PageB = 1 };
		static int index(Page page, int index);
	};

}
