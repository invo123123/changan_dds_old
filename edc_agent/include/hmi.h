
struct AutoLightStatus
{ 
    uint32_t las_hmastatus ;
}; 

struct Gatewaystatus
{ 
    uint32_t w_adssecocverifyfailureflag ;
}; 

struct SensorStatus
{ 
    uint32_t acc_fradarfailurestatus ;
    uint32_t acc_fradarcalibrationstatus ;
    uint32_t las_frontcamerafailurestatus ;
    uint32_t las_frontcameracalibrationstatus ;
    uint32_t ads_flc_systemstatus ;
    uint32_t ads_frc_systemstatus ;
    uint32_t lcdal_systemstatus ;
    uint32_t lcdar_systemstatus ;
}; 
struct LeftBSDStatus
{ 
    uint32_t lcdar_left_bsd_lcaalert ;
    uint32_t lcdar_bsd_lcaalert ;
}; 
struct FollowCarDis
{ 
    uint32_t acc_distancelevel ;
}; 
struct TakeOverEyeWarning
{ 
    uint32_t ad_handsonreq ;
    uint32_t ad_safetynotice ;
    uint32_t ad_lngtakeoverreq ;
    uint32_t ad_dynamicwarninglevel ;
    uint32_t ad_lattakeoverreq ;
    uint32_t ads_eomwarnning ;
}; 
struct ACCIACCNIDStatus
{ 
    uint32_t ad_ndastatus;
    uint32_t ad_iacchwamode ;
    uint32_t ad_tjpstatus ;
    uint32_t ad_accmode ;
}; 
struct Statefusion
{ 
	AutoLightStatus autolightstatus ;
	Gatewaystatus gatewaystatus ;
	SensorStatus sensorstatus ;
	LeftBSDStatus lrbsdstatus ;
	FollowCarDis accdislevel ;
	TakeOverEyeWarning takeovereyewarning ;
	ACCIACCNIDStatus acciaccnidstatus ;
}; 

struct ACCShowDemand
{ 
    uint32_t acc_textinfofordriver ;
    float acc_setspeed ;
    uint32_t acc_timegapset ;
    uint32_t acc_vehiclestartremindsts ;
}; 
struct IACCShowDemand
{ 
    uint32_t acc_iacchwatextinfofordriver ;
}; 
struct UDLCShowDemand
{ 

    uint32_t ads_pathshow_status ;
    float ads_totargetlatdistance ;
    uint32_t ads_udlctextinfofordriver ;
}; 
struct NIDShowDemand
{ 

    uint32_t ads_ndatextinfo ;
    uint32_t ads_ndafenceterminaldis ;
    uint32_t ads_oastatus ;
    uint32_t ads_oadirection ;
    uint32_t ads_oalatdistance ;
    uint32_t ads_oalngdistance ;
}; 
struct NewRecommend
{ 
    uint32_t ads_newrecommend ;
}; 
struct TJPNotice
{ 
    uint32_t ads_tjptextinfo ;
}; 
struct ADCNotice
{ 
    uint32_t acc_adcnotice ;
}; 
struct CNANotice
{ 
    uint32_t ads_cnatextinfo ;
}; 
struct ADAScruiseRecflag
{ 
    uint32_t ad_adascruiserecflag ;
}; 
struct SpeedLimitShowDemand
{ 
    float las_tsrhostspdlimit ;
    uint32_t las_overspeedvisualwarning ;
    uint32_t las_overspeedsoundwarning ;
    uint32_t acc_cslsetreq ;
    uint32_t ads_spdlimitedstatus ;
    uint32_t ads_spdlmttype ;
    float ads_tsrhostnextspdlimit ;
    float ads_tsrhostnextspdlimitdist ;
}; 
struct SmartDrivingTips
{ 
	ACCShowDemand acc_fun ;
	IACCShowDemand iacc_fun ;
	UDLCShowDemand udlc_fun ;
	NIDShowDemand nid_fun ;
	NewRecommend recommend_fun ;
	TJPNotice tjp_fun ;
	ADCNotice adc_funtips ;
	CNANotice cna_fun ;
	SpeedLimitShowDemand speedlimit_fun ;
    float ads_latprohibitcountdown ;
    float ads_sbuncountdown ;
    ADAScruiseRecflag ads_adascruiserec ;
}; 



struct LcdaFun
{ 
    uint32_t ad_bsdlca_leftalert ;
    uint32_t ad_rctaleftalert ;
    uint32_t ad_sealeftalert ;
    uint32_t ad_dowleftalert ;
    uint32_t ad_rcwalert ;
    uint32_t ad_bsdlca_rightalert ;
    uint32_t ad_rctarightalert ;
    uint32_t ad_searightalert ;
    uint32_t ad_dowrightalert ;
};
struct FcwAebEds
{ 
    uint32_t ad_aebstatus ;
    uint32_t ad_rebstatus ;
    uint32_t ad_aesstatus ;
    uint32_t ad_fcwlatentwarning ;
    uint32_t ad_fcwactive ;
    uint32_t ad_rewalert ;
    uint32_t ad_fctbactive ;
    uint32_t ad_rctbactive ;
    uint32_t ad_rebactive ;
    uint32_t ad_fctaleftalert ;
    uint32_t ad_fctarightalert ;
    uint32_t ad_aebactive ;
    uint32_t ad_runredlightwarning ;
    uint32_t ad_aesactive ;
}; 
struct LdwLkaElk
{ 
    uint32_t ad_ldwstatus ;
    uint32_t ad_lkastatus ;
    uint32_t ad_voiceinfo ;
    uint32_t ad_elkmode ;
    uint32_t ad_elkleftinterventionmode ;
    uint32_t ad_elkrightinterventionmode ;
    uint32_t ad_ldwinhaitwarning ;
    uint32_t ad_lkainhaitwarning ;
}; 
struct ConvoyFun
{ 
    LcdaFun lcda_fun ;
    FcwAebEds fcwaebeds ;
    LdwLkaElk ldwlkaelk ;
}; 

struct LeftLaneTRCLight
{ 
    uint32_t leftlightsituation ;
    uint32_t leftlightcolor ;
    uint32_t leftlighttype ;
    uint32_t leftlightstatus ;
    uint32_t leftlightdirection ;
};
struct RightLaneTRCLight
{ 
    uint32_t rightlightsituation ;
    uint32_t rightlightcolour ;
    uint32_t rightlighttype ;
    uint32_t rightlightstatus ;
    uint32_t rightlightdirection ;
}; 
struct HostLaneTRCLight
{ 
    uint32_t hostlightsituation ;
    uint32_t hostlightcolour ;
    uint32_t hostlighttype ;
    uint32_t hostlightstatus ;
    uint32_t hostlightdirection ;
    uint32_t hostlightwarninglevel ;
}; 
struct RoadSign
{ 
    uint32_t leftsigntype ;
    float leftsignlngrange ;
    uint32_t hostsigntype ;
    float hostsignlngrange ;
    uint32_t rightsigntype ;
    float rightsignlngrange ;
}; 
struct TrafficLightScene
{ 

	LeftLaneTRCLight lefttrcdata ;
	RightLaneTRCLight righttrcdata ;
	HostLaneTRCLight hosttrcdata ;
	RoadSign roadsigndata ;
	float crossworklngrange ;
	float stoplinelngrange ;
	float yellowglinerange ;
}; 

struct TrafficSign
{ 
    uint32_t warningsign ;
    uint32_t prohibitionsign ;
    uint32_t mandatorysign ;
    uint32_t lanearrowdata ;
}; 