/*
   Copyright (c) 2020 Christof Ruch. All rights reserved.

   Dual licensed: Distributed under Affero GPL license by default, an MIT license is available for purchase
*/

#pragma once

#include "Patch.h"
#include "PatchNumber.h"
#include "DataFileSendCapability.h"

namespace midikraft {

	class VirusPatchNumber : public PatchNumber {
	public:
		using PatchNumber::PatchNumber;
		virtual std::string friendlyName() const override;
	};

	class VirusSingleModeTarget : public SendTarget {
	public:
		std::string name() const { return "Single Mode Edit Buffer"; }
	};

	class VirusMultiModePart : public SendTarget {
	public:
		VirusMultiModePart(uint8 partNo) : partNo_(partNo) {};

		std::string name() const override;

		uint8 partNo() const { return partNo_;  }

	private:
		uint8 partNo_;
	};

	class VirusPatch : public Patch, public StoredPatchNameCapability {
	public:
		VirusPatch(Synth::PatchData const &data);

		virtual std::string name() const override;
		virtual std::shared_ptr<PatchNumber> patchNumber() const override;
		virtual void setPatchNumber(MidiProgramNumber patchNumber) override;
		
		// StoredPatchNameCapability
		virtual void setName(std::string const &name) override;
		virtual bool isDefaultName() const override;

		enum DataFileTypes { PATCH_VIRUS_B = 0 };
		enum Page { PageA = 0, PageB = 1 };
		static int index(Page page, int index);

	private:
		MidiProgramNumber place_ = MidiProgramNumber::fromZeroBase(0);
	};

}
