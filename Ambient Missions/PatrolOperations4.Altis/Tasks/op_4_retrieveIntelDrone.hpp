class op_4_RetrieveIntelDrone: TaskDefaults {
	scope = 0;
	typeID = 4;

	// Random Position
	positionSearchTypes[] = {"Clearing"};
	positionSearchRadius = 1000;
	positionNearLast = 1;

	// Description
	class TaskDetails {
		title = "%1";
		description[] = {
			"<t>Ref: %2</t> | <t>Date: %3<br/>AO: %4 %5 near %6</t>"
			,"<t size='1.1' color='#FFC600'>Brief:</t> <t>FOP</t>"
			,"<t size='1.1' color='#FFC600'>Action:</t> <t>Redacted.</t>"
			,"<t size='1.1' color='#FFC600'>Enemy:</t> <t>Redacted.</t>"
			,"<t size='1.1' color='#FFC600'>Note:</t> <t>Redacted.</t>"
		};
		iconType = "Intel";
		iconPosition = "position";
		textArguments[] = {"operationName","randomCode","datetime","worldRegion","worldName","nearestTown","factionBLUshort","factionOPFshort"};
	};

	// Markers
	class Markers {
		class marker_A {
			shape = "RECTANGLE";
			brush = "SolidBorder";
			colour = "ColorOpfor";
			size[] = {0.99,0.99};
			alpha = 0.2;
		};
		class marker_B: marker_A {
			brush = "Border";
			size[] = {1.2,1.2};
			alpha = 1;
		};
		class marker_C: marker_A {
			brush = "Border";
			size[] = {1.0,1.0};
			alpha = 1;
		};
		class marker_D: marker_A {
			brush = "FDiagonal";
			size[] = {1.2,0.1};
			alpha = 0.9;
			direction = 0;
			distance = 1.1;
		};
		class marker_E: marker_D {
			direction = 180;
		};
		class marker_F: marker_D {
			size[] = {1.0,0.1};
			direction = 90;
			angle = 90;
		};
		class marker_G: marker_F {
			direction = 270;
		};
		class marker_target {
			position = "positionOffset";
			shape = "ICON";
			type = "mil_objective";
			colour = "ColorOpfor";
			size[] = {0.8,0.8};
			alpha = 0.6;
			text = "Target";
		};
	};

	class Compositions {
		class CommsTent {
			position = "positionOffset";
			typeIDs[] = {"crashsite_uav_02"};
			downloadIntel = 1;
		};
	};

	// Groups + Targets
	class Groups {
		class EN_Group_1 {
			probability = 1;
			position = "positionOffset";
			distance[] = {50,100};
			direction[] = {0,360};
			faction = "FactionTypeOPF";
			groupTypes[] = {"Squad8","Squad8_AA","Squad8_AR","Squad8_AT","Squad8_M","Squad4","Squad4_AA","Squad4_AR","Squad4_AT","Squad4_M"};
			isPatrolling = 0.8;
			radius[] = {100,250};
			isDefending = 1;
			occupyBuildings = 1;
		};
		class EN_Group_2: EN_Group_1 {
			probability = 0.7;
		};
		class EN_Group_3: EN_Group_1 {
			probability = 0.5;
		};
		class EN_Group_4: EN_Group_1 {
			probability = 0.3;
		};
		class EN_Vehicle_Group_1 {
			probability = 1;
			position = "positionOffset";
			distance[] = {50,100};
			direction[] = {0,360};
			faction = "FactionTypeOPF";
			vehicleTypes[] = {"CarTurret","Car"};
			createCrew = 1;
			isPatrolling = 0.6;
			radius[] = {150,250};
		};
		class EN_Vehicle_Group_2: EN_Vehicle_Group_1 {
			probability = 0.7;
			vehicleTypes[] = {"CarTurret","ArmourAA","ArmourAPC"};
		};
		class EN_Vehicle_Group_3: EN_Vehicle_Group_1 {
			probability = 0.3;
			vehicleTypes[] = {"ArmourAA","ArmourAPC"};
		};
	};

	class EventHandlers {
		class onIntelDownloadStart { code = "[_this,true] call MPSF_fnc_taskIntelAmbush"; };
		//class onIntelDownloadStop { code = "[_this,false] call MPSF_fnc_taskIntelAmbush"; };
		class onIntelDownloaded { code = "[_this,false] call MPSF_fnc_taskIntelAmbush"; };
	};

	// Objective Condition
	class Objective {
		class Succeeded {
			condition = "_intelDownloaded";
		};
	};
};