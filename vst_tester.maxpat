{
	"patcher" : 	{
		"fileversion" : 1,
		"appversion" : 		{
			"major" : 8,
			"minor" : 5,
			"revision" : 6,
			"architecture" : "x64",
			"modernui" : 1
		}
,
		"classnamespace" : "box",
		"rect" : [ 34.0, 87.0, 972.0, 869.0 ],
		"bglocked" : 0,
		"openinpresentation" : 1,
		"default_fontsize" : 12.0,
		"default_fontface" : 0,
		"default_fontname" : "Arial",
		"gridonopen" : 1,
		"gridsize" : [ 15.0, 15.0 ],
		"gridsnaponopen" : 1,
		"objectsnaponopen" : 1,
		"statusbarvisible" : 2,
		"toolbarvisible" : 1,
		"lefttoolbarpinned" : 0,
		"toptoolbarpinned" : 0,
		"righttoolbarpinned" : 0,
		"bottomtoolbarpinned" : 0,
		"toolbars_unpinned_last_save" : 0,
		"tallnewobj" : 0,
		"boxanimatetime" : 200,
		"enablehscroll" : 1,
		"enablevscroll" : 1,
		"devicewidth" : 0.0,
		"description" : "",
		"digest" : "",
		"tags" : "",
		"style" : "",
		"subpatcher_template" : "",
		"assistshowspatchername" : 0,
		"boxes" : [ 			{
				"box" : 				{
					"id" : "obj-46",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 659.0, 215.0, 150.0, 20.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 290.0, 171.952829837799072, 55.0, 20.0 ],
					"text" : "Presets"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-19",
					"maxclass" : "preset",
					"numinlets" : 1,
					"numoutlets" : 5,
					"outlettype" : [ "preset", "int", "preset", "int", "" ],
					"patching_rect" : [ 599.0, 271.0, 100.0, 40.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 290.0, 192.952829837799072, 100.0, 40.0 ],
					"preset_data" : [ 						{
							"number" : 1,
							"data" : [ 5, "obj-38", "toggle", "int", 0, 5, "obj-34", "toggle", "int", 0, 5, "obj-4", "live.gain~", "float", -6.0, 5, "obj-14", "attrui", "attr", "sono", 5, "obj-14", "attrui", "int", 0, 5, "obj-21", "attrui", "attr", "interval", 5, "obj-21", "attrui", "int", 200, 5, "obj-17", "attrui", "attr", "logamp", 5, "obj-17", "attrui", "int", 1, 5, "obj-8", "attrui", "attr", "domain", 6, "obj-8", "attrui", "list", 0.0, 24000.0, 5, "obj-25", "attrui", "attr", "range", 6, "obj-25", "attrui", "list", 0.0, 1.0, 5, "obj-32", "umenu", "int", 0, 5, "obj-1", "playlist~", "preset_count", 4, 7, "obj-1", "playlist~", "preset_clipstate", 1, "filekind", "audiofile", 7, "obj-1", "playlist~", "preset_clipstate", 1, "absolutepath", "/Users/ruari/Documents/SAMPLES/sounds/OPN_Replica_SP555_CF_Samples/D15.wav", 7, "obj-1", "playlist~", "preset_clipstate", 1, "filename", "D15.wav", 7, "obj-1", "playlist~", "preset_clipstate", 1, "loop", 1, 8, "obj-1", "playlist~", "preset_clipstate", 1, "selection", -1.0, -1.0, 7, "obj-1", "playlist~", "preset_clipstate", 1, "id", "u005001023", 7, "obj-1", "playlist~", "preset_content", 1, "loop", 1, 7, "obj-1", "playlist~", "preset_clipstate", 2, "filekind", "audiofile", 7, "obj-1", "playlist~", "preset_clipstate", 2, "absolutepath", "/Users/ruari/Documents/SAMPLES/sounds/OPN_Replica_SP555_CF_Samples/E4.wav", 7, "obj-1", "playlist~", "preset_clipstate", 2, "filename", "E4.wav", 7, "obj-1", "playlist~", "preset_clipstate", 2, "loop", 1, 8, "obj-1", "playlist~", "preset_clipstate", 2, "selection", -1.0, -1.0, 7, "obj-1", "playlist~", "preset_clipstate", 2, "id", "u603001031", 7, "obj-1", "playlist~", "preset_content", 2, "loop", 1, 7, "obj-1", "playlist~", "preset_clipstate", 3, "filekind", "audiofile", 7, "obj-1", "playlist~", "preset_clipstate", 3, "absolutepath", "/Users/ruari/Documents/SAMPLES/sounds/OPN_Replica_SP555_CF_Samples/E7.wav", 7, "obj-1", "playlist~", "preset_clipstate", 3, "filename", "E7.wav", 7, "obj-1", "playlist~", "preset_clipstate", 3, "loop", 0, 8, "obj-1", "playlist~", "preset_clipstate", 3, "selection", -1.0, -1.0, 7, "obj-1", "playlist~", "preset_clipstate", 3, "id", "u400001038", 7, "obj-1", "playlist~", "preset_clipstate", 4, "filekind", "audiofile", 7, "obj-1", "playlist~", "preset_clipstate", 4, "absolutepath", "/Users/ruari/Documents/SAMPLES/sounds/OPN_Replica_SP555_CF_Samples/E9.wav", 7, "obj-1", "playlist~", "preset_clipstate", 4, "filename", "E9.wav", 7, "obj-1", "playlist~", "preset_clipstate", 4, "loop", 1, 8, "obj-1", "playlist~", "preset_clipstate", 4, "selection", -1.0, -1.0, 7, "obj-1", "playlist~", "preset_clipstate", 4, "id", "u628001045", 7, "obj-1", "playlist~", "preset_content", 4, "loop", 1, 4, "obj-1", "playlist~", "preset_execute", 5, "obj-13", "toggle", "int", 1, 5, "obj-27", "toggle", "int", 0, 5, "obj-30", "toggle", "int", 0, 5, "obj-37", "number", "int", 440 ]
						}
, 						{
							"number" : 2,
							"data" : [ 5, "obj-38", "toggle", "int", 0, 5, "obj-34", "toggle", "int", 0, 5, "obj-4", "live.gain~", "float", -6.0, 5, "obj-14", "attrui", "attr", "sono", 5, "obj-14", "attrui", "int", 1, 5, "obj-21", "attrui", "attr", "interval", 5, "obj-21", "attrui", "int", 20, 5, "obj-17", "attrui", "attr", "logamp", 5, "obj-17", "attrui", "int", 1, 5, "obj-8", "attrui", "attr", "domain", 6, "obj-8", "attrui", "list", 0.0, 24000.0, 5, "obj-25", "attrui", "attr", "range", 6, "obj-25", "attrui", "list", 0.0, 1.0, 5, "obj-32", "umenu", "int", 0, 5, "obj-1", "playlist~", "preset_count", 4, 7, "obj-1", "playlist~", "preset_clipstate", 1, "filekind", "audiofile", 7, "obj-1", "playlist~", "preset_clipstate", 1, "absolutepath", "/Users/ruari/Documents/SAMPLES/sounds/OPN_Replica_SP555_CF_Samples/D15.wav", 7, "obj-1", "playlist~", "preset_clipstate", 1, "filename", "D15.wav", 7, "obj-1", "playlist~", "preset_clipstate", 1, "loop", 1, 8, "obj-1", "playlist~", "preset_clipstate", 1, "selection", -1.0, -1.0, 7, "obj-1", "playlist~", "preset_clipstate", 1, "id", "u005001023", 7, "obj-1", "playlist~", "preset_content", 1, "loop", 1, 7, "obj-1", "playlist~", "preset_clipstate", 2, "filekind", "audiofile", 7, "obj-1", "playlist~", "preset_clipstate", 2, "absolutepath", "/Users/ruari/Documents/SAMPLES/sounds/OPN_Replica_SP555_CF_Samples/E4.wav", 7, "obj-1", "playlist~", "preset_clipstate", 2, "filename", "E4.wav", 7, "obj-1", "playlist~", "preset_clipstate", 2, "loop", 1, 8, "obj-1", "playlist~", "preset_clipstate", 2, "selection", -1.0, -1.0, 7, "obj-1", "playlist~", "preset_clipstate", 2, "id", "u603001031", 7, "obj-1", "playlist~", "preset_content", 2, "loop", 1, 7, "obj-1", "playlist~", "preset_clipstate", 3, "filekind", "audiofile", 7, "obj-1", "playlist~", "preset_clipstate", 3, "absolutepath", "/Users/ruari/Documents/SAMPLES/sounds/OPN_Replica_SP555_CF_Samples/E7.wav", 7, "obj-1", "playlist~", "preset_clipstate", 3, "filename", "E7.wav", 7, "obj-1", "playlist~", "preset_clipstate", 3, "loop", 0, 8, "obj-1", "playlist~", "preset_clipstate", 3, "selection", -1.0, -1.0, 7, "obj-1", "playlist~", "preset_clipstate", 3, "id", "u400001038", 7, "obj-1", "playlist~", "preset_clipstate", 4, "filekind", "audiofile", 7, "obj-1", "playlist~", "preset_clipstate", 4, "absolutepath", "/Users/ruari/Documents/SAMPLES/sounds/OPN_Replica_SP555_CF_Samples/E9.wav", 7, "obj-1", "playlist~", "preset_clipstate", 4, "filename", "E9.wav", 7, "obj-1", "playlist~", "preset_clipstate", 4, "loop", 1, 8, "obj-1", "playlist~", "preset_clipstate", 4, "selection", -1.0, -1.0, 7, "obj-1", "playlist~", "preset_clipstate", 4, "id", "u628001045", 7, "obj-1", "playlist~", "preset_content", 4, "loop", 1, 4, "obj-1", "playlist~", "preset_execute", 5, "obj-13", "toggle", "int", 1, 5, "obj-27", "toggle", "int", 0, 5, "obj-30", "toggle", "int", 0, 5, "obj-37", "number", "int", 440 ]
						}
 ]
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-61",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 667.0, 185.0, 150.0, 20.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 514.0, 163.452829837799072, 65.0, 20.0 ],
					"text" : "Freq (Hz)"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-54",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 589.0, 623.0, 47.0, 20.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 514.0, 117.0, 47.0, 20.0 ],
					"text" : "Sine"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-50",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 589.0, 501.5, 47.0, 20.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 466.0, 117.5, 47.0, 20.0 ],
					"text" : "Pink"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-45",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 589.0, 405.5, 47.0, 20.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 416.696287482757498, 117.5, 47.0, 20.0 ],
					"text" : "Noise"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-43",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 394.0, 581.0, 83.0, 22.0 ],
					"text" : "loadmess 440"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-40",
					"maxclass" : "newobj",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "multichannelsignal" ],
					"patching_rect" : [ 634.0, 623.0, 92.0, 22.0 ],
					"text" : "mc.mixdown~ 1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-37",
					"maxclass" : "number",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "bang" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 506.0, 635.0, 50.0, 22.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 514.0, 184.452829837799072, 50.0, 22.0 ]
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-28",
					"maxclass" : "newobj",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "signal" ],
					"patching_rect" : [ 506.0, 693.0, 34.0, 22.0 ],
					"text" : "*~ 0."
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-30",
					"maxclass" : "toggle",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "int" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 589.0, 645.5, 24.0, 24.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 514.0, 139.5, 24.0, 24.0 ]
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-26",
					"maxclass" : "newobj",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "signal" ],
					"patching_rect" : [ 506.0, 571.0, 34.0, 22.0 ],
					"text" : "*~ 0."
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-27",
					"maxclass" : "toggle",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "int" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 589.0, 523.5, 24.0, 24.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 466.0, 139.5, 24.0, 24.0 ]
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-24",
					"maxclass" : "newobj",
					"numinlets" : 3,
					"numoutlets" : 1,
					"outlettype" : [ "multichannelsignal" ],
					"patching_rect" : [ 634.0, 556.0, 70.0, 22.0 ],
					"text" : "mc.pack~ 3"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-16",
					"maxclass" : "newobj",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "signal" ],
					"patching_rect" : [ 506.0, 475.0, 34.0, 22.0 ],
					"text" : "*~ 0."
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-13",
					"maxclass" : "toggle",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "int" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 589.0, 427.5, 24.0, 24.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 416.696287482757498, 139.5, 24.0, 24.0 ]
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-9",
					"maxclass" : "newobj",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "signal" ],
					"patching_rect" : [ 506.0, 659.0, 43.0, 22.0 ],
					"text" : "cycle~"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-7",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "signal" ],
					"patching_rect" : [ 506.0, 521.0, 38.0, 22.0 ],
					"text" : "pink~"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-2",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "signal" ],
					"patching_rect" : [ 506.0, 427.5, 44.0, 22.0 ],
					"text" : "noise~"
				}

			}
, 			{
				"box" : 				{
					"basictuning" : 0,
					"clipheight" : 22.0,
					"data" : 					{
						"clips" : [ 							{
								"absolutepath" : "/Users/ruari/Documents/SAMPLES/sounds/OPN_Replica_SP555_CF_Samples/D15.wav",
								"filename" : "D15.wav",
								"filekind" : "audiofile",
								"id" : "u005001023",
								"loop" : 1,
								"content_state" : 								{
									"loop" : 1
								}

							}
, 							{
								"absolutepath" : "/Users/ruari/Documents/SAMPLES/sounds/OPN_Replica_SP555_CF_Samples/E4.wav",
								"filename" : "E4.wav",
								"filekind" : "audiofile",
								"id" : "u603001031",
								"loop" : 1,
								"content_state" : 								{
									"loop" : 1
								}

							}
, 							{
								"absolutepath" : "/Users/ruari/Documents/SAMPLES/sounds/OPN_Replica_SP555_CF_Samples/E7.wav",
								"filename" : "E7.wav",
								"filekind" : "audiofile",
								"id" : "u400001038",
								"loop" : 0,
								"content_state" : 								{

								}

							}
, 							{
								"absolutepath" : "/Users/ruari/Documents/SAMPLES/sounds/OPN_Replica_SP555_CF_Samples/E9.wav",
								"filename" : "E9.wav",
								"filekind" : "audiofile",
								"id" : "u628001045",
								"loop" : 1,
								"content_state" : 								{
									"loop" : 1
								}

							}
 ]
					}
,
					"followglobaltempo" : 0,
					"formantcorrection" : 0,
					"id" : "obj-1",
					"maxclass" : "playlist~",
					"mode" : "basic",
					"numinlets" : 1,
					"numoutlets" : 5,
					"originallength" : [ 0 ],
					"originaltempo" : 0,
					"outlettype" : [ "signal", "signal", "signal", "", "dictionary" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 258.0, 346.0, 150.0, 92.0 ],
					"pitchcorrection" : 0,
					"presentation" : 1,
					"presentation_rect" : [ 417.696287482757498, 17.0, 150.0, 91.452829837799072 ],
					"quality" : "basic",
					"timestretch" : [ 0 ]
				}

			}
, 			{
				"box" : 				{
					"activebgcolor" : [ 0.0, 0.0, 0.0, 1.0 ],
					"grid" : 3,
					"id" : "obj-41",
					"maxclass" : "live.scope~",
					"mode" : 1,
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "bang" ],
					"patching_rect" : [ 203.782372994636717, 687.273742377758026, 184.0, 68.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 20.0, 596.273742377758026, 546.0, 223.0 ],
					"rounded" : 0.0,
					"trigger_threshold" : 0.01
				}

			}
, 			{
				"box" : 				{
					"fontface" : 0,
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"id" : "obj-32",
					"items" : [ "Forward", "Draw", ",", "Reverse", "Draw", ",", "Forward", "Scroll", ",", "Reverse", "Scroll" ],
					"maxclass" : "umenu",
					"numinlets" : 1,
					"numoutlets" : 3,
					"outlettype" : [ "int", "", "" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 584.0, 134.0, 114.0, 23.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 387.696287482757441, 274.555542000000003, 114.0, 23.0 ]
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"id" : "obj-33",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 578.0, 178.0, 58.0, 23.0 ],
					"text" : "scroll $1"
				}

			}
, 			{
				"box" : 				{
					"attr" : "range",
					"attrfilter" : [ "range" ],
					"fontface" : 0,
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"id" : "obj-25",
					"lock" : 1,
					"maxclass" : "attrui",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 584.0, 58.5, 180.0, 23.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 203.696287482757441, 247.0, 180.0, 23.0 ],
					"text_width" : 60.0
				}

			}
, 			{
				"box" : 				{
					"attr" : "domain",
					"attrfilter" : [ "domain" ],
					"fontface" : 0,
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"id" : "obj-8",
					"lock" : 1,
					"maxclass" : "attrui",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 584.0, 97.555542000000003, 180.0, 23.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 203.696287482757441, 274.555542000000003, 180.0, 23.0 ],
					"text_width" : 60.0
				}

			}
, 			{
				"box" : 				{
					"attr" : "logamp",
					"fontface" : 0,
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"id" : "obj-17",
					"lock" : 1,
					"maxclass" : "attrui",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 387.5, 139.944427000000019, 180.0, 23.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 19.696287482757441, 247.0, 180.0, 23.0 ],
					"text_width" : 60.0
				}

			}
, 			{
				"box" : 				{
					"attr" : "interval",
					"attrfilter" : [ "interval" ],
					"fontface" : 0,
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"id" : "obj-21",
					"lock" : 1,
					"maxclass" : "attrui",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 387.5, 58.5, 180.0, 23.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 387.696287482757441, 247.0, 180.0, 23.0 ],
					"text_width" : 60.0
				}

			}
, 			{
				"box" : 				{
					"attr" : "sono",
					"attrfilter" : [ "sono" ],
					"fontface" : 0,
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"id" : "obj-14",
					"lock" : 1,
					"maxclass" : "attrui",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 387.5, 97.555542000000003, 180.0, 23.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 19.696287482757441, 274.555542000000003, 180.0, 23.0 ],
					"text_width" : 60.0
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"id" : "obj-10",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 457.5, 199.0, 68.0, 23.0 ],
					"text" : "logfreq $1"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"id" : "obj-29",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 387.5, 199.0, 61.0, 23.0 ],
					"text" : "range $1"
				}

			}
, 			{
				"box" : 				{
					"domain" : [ 0.0, 24000.0 ],
					"id" : "obj-31",
					"logfreq" : 1,
					"markercolor" : [ 0.0, 0.0, 0.0, 1.0 ],
					"maxclass" : "spectroscope~",
					"monochrome" : 0,
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 387.5, 250.0, 300.0, 100.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 20.0, 304.0, 546.0, 286.0 ],
					"range" : [ 0.0, 1.0 ],
					"scroll" : 3,
					"sono" : 1
				}

			}
, 			{
				"box" : 				{
					"clip_size" : 1,
					"id" : "obj-4",
					"lastchannelcount" : 0,
					"maxclass" : "live.gain~",
					"numinlets" : 2,
					"numoutlets" : 5,
					"orientation" : 1,
					"outlettype" : [ "signal", "signal", "", "float", "list" ],
					"parameter_enable" : 1,
					"patching_rect" : [ 21.0, 303.0, 181.0, 47.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 96.0, 189.452829837799072, 181.0, 47.0 ],
					"saved_attribute_attributes" : 					{
						"valueof" : 						{
							"parameter_longname" : "live.gain~",
							"parameter_mmax" : 6.0,
							"parameter_mmin" : -70.0,
							"parameter_shortname" : "live.gain~",
							"parameter_type" : 0,
							"parameter_unitstyle" : 4
						}

					}
,
					"varname" : "live.gain~"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-22",
					"local" : 1,
					"maxclass" : "ezdac~",
					"numinlets" : 2,
					"numoutlets" : 0,
					"patching_rect" : [ 21.0, 441.0, 44.0, 44.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 20.0, 189.452829837799072, 44.0, 44.0 ]
				}

			}
, 			{
				"box" : 				{
					"autosave" : 1,
					"bgmode" : 0,
					"border" : 0,
					"clickthrough" : 0,
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"id" : "obj-35",
					"maxclass" : "newobj",
					"numinlets" : 2,
					"numoutlets" : 8,
					"offset" : [ 0.0, 0.0 ],
					"outlettype" : [ "signal", "signal", "", "list", "int", "", "", "" ],
					"patching_rect" : [ 21.0, 261.0, 92.5, 23.0 ],
					"save" : [ "#N", "vst~", "loaduniqueid", 0, ";" ],
					"saved_attribute_attributes" : 					{
						"valueof" : 						{
							"parameter_invisible" : 1,
							"parameter_longname" : "vst~",
							"parameter_shortname" : "vst~",
							"parameter_type" : 3
						}

					}
,
					"saved_object_attributes" : 					{
						"parameter_enable" : 1,
						"parameter_mappable" : 0
					}
,
					"snapshot" : 					{
						"filetype" : "C74Snapshot",
						"version" : 2,
						"minorversion" : 0,
						"name" : "snapshotlist",
						"origin" : "vst~",
						"type" : "list",
						"subtype" : "Undefined",
						"embed" : 1,
						"snapshot" : 						{
							"pluginname" : "graphic_equaliser_4.vst3",
							"plugindisplayname" : "graphic_equaliser_4",
							"pluginsavedname" : "~/Documents/SoundandMusicMsc/audio_programming/audio_programming_labs/lab_3/graphic_equaliser_parallel/Builds/MacOSX/build/Debug/graphic_equaliser_4.vst3",
							"pluginsaveduniqueid" : 0,
							"version" : 1,
							"isbank" : 0,
							"isbase64" : 1,
							"blob" : "152.VMjLg7H....OVMEUy.Ea0cVZtMEcgQWY9vSRC8Vav8lak4Fc9XCLt3hKt3hKt3hKt3hYRUUSTEETIckVwTjQisVTTgkdEYjKAQjYPQSPWgUdMcjKAQjct3hdA4hKt3hKt3hKtnTUv.UQAslXuk0UXoWUFE0YQcEV77RRC8Vav8lak4Fc9vyKVMEUy.Ea0cVZtMEcgQWY9.."
						}
,
						"snapshotlist" : 						{
							"current_snapshot" : 0,
							"entries" : [ 								{
									"filetype" : "C74Snapshot",
									"version" : 2,
									"minorversion" : 0,
									"name" : "graphic_equaliser_4",
									"origin" : "graphic_equaliser_4.vst3",
									"type" : "VST3",
									"subtype" : "AudioEffect",
									"embed" : 1,
									"snapshot" : 									{
										"pluginname" : "graphic_equaliser_4.vst3",
										"plugindisplayname" : "graphic_equaliser_4",
										"pluginsavedname" : "~/Documents/SoundandMusicMsc/audio_programming/audio_programming_labs/lab_3/graphic_equaliser_parallel/Builds/MacOSX/build/Debug/graphic_equaliser_4.vst3",
										"pluginsaveduniqueid" : 0,
										"version" : 1,
										"isbank" : 0,
										"isbase64" : 1,
										"blob" : "152.VMjLg7H....OVMEUy.Ea0cVZtMEcgQWY9vSRC8Vav8lak4Fc9XCLt3hKt3hKt3hKt3hYRUUSTEETIckVwTjQisVTTgkdEYjKAQjYPQSPWgUdMcjKAQjct3hdA4hKt3hKt3hKtnTUv.UQAslXuk0UXoWUFE0YQcEV77RRC8Vav8lak4Fc9vyKVMEUy.Ea0cVZtMEcgQWY9.."
									}
,
									"fileref" : 									{
										"name" : "graphic_equaliser_4",
										"filename" : "graphic_equaliser_4.maxsnap",
										"filepath" : "~/Documents/Max 8/Snapshots",
										"filepos" : -1,
										"snapshotfileid" : "de2d05555cbc996beca0e7b9777c2fe5"
									}

								}
 ]
						}

					}
,
					"text" : "vst~",
					"varname" : "vst~",
					"viewvisibility" : 0
				}

			}
, 			{
				"box" : 				{
					"bubble" : 1,
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"id" : "obj-6",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 97.0, 104.0, 184.0, 25.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 97.0, 96.452829837799072, 184.0, 25.0 ],
					"text" : "close the interface window"
				}

			}
, 			{
				"box" : 				{
					"bubble" : 1,
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"id" : "obj-5",
					"linecount" : 2,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 97.0, 58.5, 214.0, 40.0 ],
					"presentation" : 1,
					"presentation_linecount" : 2,
					"presentation_rect" : [ 97.0, 50.952829837799072, 214.0, 40.0 ],
					"text" : "open the interface window (or double click on vst~ object box)"
				}

			}
, 			{
				"box" : 				{
					"bubble" : 1,
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"id" : "obj-3",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 97.0, 31.0, 173.0, 25.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 97.0, 23.452829837799072, 173.0, 25.0 ],
					"text" : "select and load a plug-in"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-34",
					"maxclass" : "toggle",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "int" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 21.0, 184.0, 24.0, 24.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 97.0, 161.452829837799072, 24.0, 24.0 ]
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"id" : "obj-20",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 21.0, 209.0, 70.0, 23.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 20.0, 161.452829837799072, 70.0, 23.0 ],
					"text" : "bypass $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-38",
					"maxclass" : "toggle",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "int" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 21.0, 134.0, 24.0, 24.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 97.0, 130.452829837799072, 24.0, 24.0 ]
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"id" : "obj-39",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 21.0, 159.0, 70.0, 23.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 20.0, 130.452829837799072, 70.0, 23.0 ],
					"text" : "disable $1"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"id" : "obj-18",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 20.0, 107.0, 70.0, 23.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 20.0, 99.452829837799072, 70.0, 23.0 ],
					"text" : "wclose"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"id" : "obj-15",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 20.0, 69.0, 70.0, 23.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 20.0, 61.452829837799072, 70.0, 23.0 ],
					"text" : "open"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"id" : "obj-12",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 20.0, 34.0, 70.0, 23.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 20.0, 26.452829837799072, 70.0, 23.0 ],
					"text" : "plug"
				}

			}
, 			{
				"box" : 				{
					"angle" : 270.0,
					"border" : 2,
					"bordercolor" : [ 0.035294117647059, 0.035294117647059, 0.035294117647059, 1.0 ],
					"grad1" : [ 0.8, 0.945098039215686, 0.792156862745098, 1.0 ],
					"grad2" : [ 1.0, 0.870588235294118, 0.870588235294118, 1.0 ],
					"id" : "obj-23",
					"maxclass" : "panel",
					"mode" : 1,
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 25.66666579246521, 456.5, 24.666678547859192, 22.5 ],
					"presentation" : 1,
					"presentation_rect" : [ 6.66666579246521, 7.119487524032593, 574.059243380584462, 825.33333945274353 ],
					"proportion" : 0.5
				}

			}
 ],
		"lines" : [ 			{
				"patchline" : 				{
					"destination" : [ "obj-35", 1 ],
					"source" : [ "obj-1", 1 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-35", 0 ],
					"source" : [ "obj-1", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-31", 0 ],
					"source" : [ "obj-10", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-35", 0 ],
					"source" : [ "obj-12", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-16", 1 ],
					"source" : [ "obj-13", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-31", 0 ],
					"source" : [ "obj-14", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-35", 0 ],
					"source" : [ "obj-15", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-24", 0 ],
					"source" : [ "obj-16", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-31", 0 ],
					"source" : [ "obj-17", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-35", 0 ],
					"source" : [ "obj-18", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-16", 0 ],
					"source" : [ "obj-2", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-35", 0 ],
					"source" : [ "obj-20", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-31", 0 ],
					"source" : [ "obj-21", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-40", 0 ],
					"source" : [ "obj-24", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-31", 0 ],
					"source" : [ "obj-25", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-24", 1 ],
					"source" : [ "obj-26", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-26", 1 ],
					"source" : [ "obj-27", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-24", 2 ],
					"source" : [ "obj-28", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-31", 0 ],
					"source" : [ "obj-29", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-28", 1 ],
					"source" : [ "obj-30", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-33", 0 ],
					"source" : [ "obj-32", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-31", 0 ],
					"source" : [ "obj-33", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-20", 0 ],
					"source" : [ "obj-34", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-31", 0 ],
					"order" : 0,
					"source" : [ "obj-35", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-4", 1 ],
					"source" : [ "obj-35", 1 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-4", 0 ],
					"order" : 2,
					"source" : [ "obj-35", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-41", 0 ],
					"order" : 1,
					"source" : [ "obj-35", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-9", 0 ],
					"source" : [ "obj-37", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-39", 0 ],
					"source" : [ "obj-38", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-35", 0 ],
					"source" : [ "obj-39", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-22", 1 ],
					"source" : [ "obj-4", 1 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-22", 0 ],
					"source" : [ "obj-4", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-35", 1 ],
					"order" : 0,
					"source" : [ "obj-40", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-35", 0 ],
					"order" : 1,
					"source" : [ "obj-40", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-37", 0 ],
					"source" : [ "obj-43", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-26", 0 ],
					"source" : [ "obj-7", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-31", 0 ],
					"source" : [ "obj-8", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-28", 0 ],
					"source" : [ "obj-9", 0 ]
				}

			}
 ],
		"parameters" : 		{
			"obj-35" : [ "vst~", "vst~", 0 ],
			"obj-4" : [ "live.gain~", "live.gain~", 0 ],
			"parameterbanks" : 			{
				"0" : 				{
					"index" : 0,
					"name" : "",
					"parameters" : [ "-", "-", "-", "-", "-", "-", "-", "-" ]
				}

			}
,
			"inherited_shortname" : 1
		}
,
		"dependency_cache" : [ 			{
				"name" : "D15.wav",
				"bootpath" : "~/Documents/SAMPLES/sounds/OPN_Replica_SP555_CF_Samples",
				"patcherrelativepath" : "../../../SAMPLES/sounds/OPN_Replica_SP555_CF_Samples",
				"type" : "WAVE",
				"implicit" : 1
			}
, 			{
				"name" : "E4.wav",
				"bootpath" : "~/Documents/SAMPLES/sounds/OPN_Replica_SP555_CF_Samples",
				"patcherrelativepath" : "../../../SAMPLES/sounds/OPN_Replica_SP555_CF_Samples",
				"type" : "WAVE",
				"implicit" : 1
			}
, 			{
				"name" : "E7.wav",
				"bootpath" : "~/Documents/SAMPLES/sounds/OPN_Replica_SP555_CF_Samples",
				"patcherrelativepath" : "../../../SAMPLES/sounds/OPN_Replica_SP555_CF_Samples",
				"type" : "WAVE",
				"implicit" : 1
			}
, 			{
				"name" : "E9.wav",
				"bootpath" : "~/Documents/SAMPLES/sounds/OPN_Replica_SP555_CF_Samples",
				"patcherrelativepath" : "../../../SAMPLES/sounds/OPN_Replica_SP555_CF_Samples",
				"type" : "WAVE",
				"implicit" : 1
			}
, 			{
				"name" : "graphic_equaliser_4.maxsnap",
				"bootpath" : "~/Documents/Max 8/Snapshots",
				"patcherrelativepath" : "../../../Max 8/Snapshots",
				"type" : "mx@s",
				"implicit" : 1
			}
 ],
		"autosave" : 0
	}

}
