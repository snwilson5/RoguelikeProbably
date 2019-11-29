# pragma once
# include <string>
# include "Map.h"
using namespace std;

class GameMaps
{
public:
	static string Map_0_0()
	{
		 string map =  "M M M M M M M M M M M M M M M M M M M M M M M M M M M M M M\n";
			    map += "M M M M M M                         T                     >\n";
				map += "M M                     T                                 >\n";
				map += "M     # # # # # # #               g                 T     >\n";
				map += "M     #[]         #                                       >\n";
				map += "M     #           #                                       >\n";
				map += "M     #           #                                       >\n";
				map += "M     #           #           T                 T         >\n";
				map += "M     #           #               ê                       >\n";
				map += "M     # # # ? # # #                                       >\n";
				map += "M M                                                       >\n";
				map += "M M                       T                               >\n";
				map += "M M M                                                     >\n";
				map += "M M M                                   T                 >\n";
				map += "M M M             T                                       >\n";
				map += "M M M                                         T           >\n";
				map += "M M M T                                                   >\n";
				map += "M M M                           T                         >\n";
				map += "M M M M                                                   >\n";
				map += "M M M M v v v v v v v v v v v v v v v v v v v v v v v v v  \n";
		 return map;
	}
	static string Map_1_0()
	{
		string  map =  "M M M M M M M M M M M M M M M M M M M M M M M M M M M M M M\n";
			    map += "<                                                         >\n";
		        map += "<     T   # # # #     # # # #              T            >\n";
				map += "<         #     #     #     #                             >\n";
				map += "<        #     #     #     #           # # # # # # #     >\n";
				map += "<         # # ? #     # # ï #           #           #     >\n";
				map += "<         T                       T     #           #     >\n";
				map += "<                                      #           #     >\n";
				map += "<                                      #           #     >\n";
				map += "<                                       ï           #     >\n";
				map += "<                                      #           #     >\n";
				map += "<                                      #           #     >\n";
				map += "<                                 T     #           #     >\n";
				map += "<         # #   #     # # ¿ #           #           #     >\n";
				map += "<         #     #     #     #          #           #     >\n";
				map += "<         #     #     #     #           # # # # # # #     >\n";
				map += "<        # # # #     # # # #                             >\n";
				map += "<                       T                               >\n";
				map += "<                                                         >\n";
				map += "  v v v v v v v v v v v v v v v v v v v v v v v v v v v v  \n";
		return  map;
	}

	static string Map_2_0()
	{
		string map =  "M M M M M M M M M M M M M M M M M M M M M M M M M M M M M M\n";
			   map += "<                     T       M M M M M C C C C M M M M M M\n";
			   map += "<                               M M M M C |   C C C C M M M\n";
			   map += "<       T                         M M M C           C M M M\n";
			   map += "<   T                    T           M C C C C C   C M M M\n";
			   map += "<                                       M M M M C   C M M M\n";
			   map += "<                T                       M M M C   C M M M\n";
			   map += "<                                            M C ? C M M M\n";
			   map += "<         T                T                 M M   M M M M\n";
			   map += "<                                                   M M M M\n";
			   map += "<                                                    M M M\n";
			   map += "<       T                             T               M M M\n";
			   map += "<                                                    M M M\n";
			   map += "<                     T                                 M M\n";
			   map += "<                                                     M M\n";
			   map += "<                           T                   T       M M\n";
			   map += "<     T                                               M M\n";
			   map += "<                                      T             M M\n";
			   map += "<                                                       M M\n";
			   map += "  v v v v v v v v v v v v v v v v v v v v v v v v v v v M M\n";
		return map;
	}

	static string Map_0_1()
	{
		string map  = "M M M M ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^  \n";
			   map += "M M M M                                                  >\n";
			   map += "M M M M M         T                                      >\n";
			   map += "M M M M M                                               >\n";
			   map += "M M M M M M                                             >\n";
			   map += "M M M M M M M M             T           T                 >\n";
			   map += "M M M M M M M M M     T                                   >\n";
			   map += "M M M M M M M M M M                          T           >\n";
			   map += "M M M M M M M M M M M                                    >\n";
			   map += "M M M M M M M M M M M M M             T                   >\n";
			   map += "M M M M M M M M M M M M M M                              >\n";
			   map += "M M M M M M M M M M M M M M M M               T           >\n";
			   map += "M M M M M M M M M M M M M M M M M                         >\n";
			   map += "M # # # # # # # M M M M M M M M M M M M                  >\n";
			   map += "M #           # M M M M M M M M M M M M M M M             >\n";
			   map += "M #           # M M M M M M M M M M M M M M M M M M M M M M\n";
			   map += "M #           # M M M M M M M M M M M M M M M M M M M M M M\n";
			   map += "M # # # ? # # # M M M M M M M M M M M M M M M M M M M M M M\n";
			   map += "M M M C   C M M M M M M M M M M M M M M M M M M M M M M M M\n";
			   map += "M M M C v C M M M M M M M M M M M M M M M M M M M M M M M M\n";
		return map;
	}

	static string Map_1_1()
	{
		string map  = "  ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^  \n";
			   map += "<                                                         >\n";
			   map += "<                 T                                     >\n";
			   map += "<                                                         >\n";
			   map += "<                                           T           >\n";
			   map += "<     T                                                   >\n";
			   map += "<                                                         >\n";
			   map += "<                           T                             >\n";
			   map += "<                                                         >\n";
			   map += "<                                   T                >\n";
			   map += "<                                                  >\n";
			   map += "<           T                                        >\n";
			   map += "<                                                     >\n";
			   map += "<                                                 T      >\n";
			   map += "<                                                         >\n";
			   map += "M M M M M                                                >\n";
			   map += "M M M M M M               T                              >\n";
			   map += "M M M M M M M                         T                   >\n";
			   map += "M M M M M M M                                             >\n";
			   map += "M M M M M M M v v v v v v v v v v v v v v v v v v v v v v  \n";
		return map;
	}

	static string Map_2_1()
	{
		string map =  "  ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ M M\n";
			   map += "<                                                    M M\n";
			   map += "<     T                    T                      M M\n";
			   map += "<                                                   M M\n";
			   map += "<                                                   M M\n";
			   map += "<           T                     M M           T       M M\n";
			   map += "<                             M M M M M                   M\n";
			   map += "<                          M M M M M M                   M\n";
			   map += "<                             M M M M M     T             M\n";
			   map += "<                                T                       M\n";
			   map += "<   T                                                     M\n";
			   map += "<                               M M M                     M\n";
			   map += "<                                M M M                   M\n";
			   map += "<                 T                M M                   M\n";
			   map += "<                                                         M\n";
			   map += "<         T                               T               M\n";
			   map += "<                       T                                 M\n";
			   map += "<                                                  T     M\n";
			   map += "<                                                         M\n";
			   map += "  v v v v v v v v v v v v v v v v v v v v v v v v v v v v  \n";
		return map;
	}

	static string Map_0_2()
	{
		string map  = "M M M C ^ C C C C C C C C C M M M M M M M M M M M M M M M M\n";
			   map += "M M M C   C C             C M M M M M M M M M M M M M M M M\n";
			   map += "M M M C   C C             C M M M M M M M C C C C C C C C M\n";
			   map += "M M M C   C C             C C C M M M M M C   ?         C M\n";
			   map += "M M M C   C C                 C M M M M M C   C         C M\n";
			   map += "M M M C   C C             C   C M M M M M C   C         C M\n";
			   map += "M M M C   C C             C   C M M M M M C   C         C M\n";
			   map += "M M M C   C C             C   C M M M M M C   C C C C C C M\n";
			   map += "M M M C   C C C C C C C C C   C C C C C C C   C C C C C C M\n";
			   map += "M M M C                   ¿                               >\n";
			   map += "M M M C   C C C C C C C C C   C C C C C                   >\n";
			   map += "M M M C   C M M M M M M M C   C M M M C ? C C C ? C C C C C\n";
			   map += "M M M C   C M M M M M M M C   C M M C C   C C C   C M M M M\n";
			   map += "M M M C   C M M M M M M M C   C M M C       C C   C M M M M\n";
			   map += "M M M C   C M M M M M M M C   C M M C       C C   C C M M M\n";
			   map += "M M M C   C M M M M M M M C   C M M C C C C C       C M M M\n";
			   map += "M M M C   C C C C C C C C C   C M M M M M M C       C M M M\n";
			   map += "M M M C                       C M M M M M M C       C M M M\n";
			   map += "M M M C C C C C C C C C C C C C M M M M M M C C C C C M M M\n";
			   map += "M M M M M M M M M M M M M M M M M M M M M M M M M M M M M M\n";
		return map;
	}

	static string Map_1_2()
	{
		string map  = "M M M M M M M ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^  \n";
			   map += "M M M M M M M                                       >\n";
			   map += "M M M M M M M M                                T     >\n";
			   map += "M M M M M M M M         T                                 >\n";
			   map += "M M M M M M M M                             T            >\n";
			   map += "M M M M M M M M                   T                       >\n";
			   map += "M M M M M M                                             >\n";
			   map += "M M M M M M                                       T       >\n";
			   map += "C C C M               T                                   >\n";
			   map += "<   ?                               T                    >\n";
			   map += "<   ?                                                   >\n";
			   map += "C C C M                                               T   >\n";
			   map += "M M M M                         T                         >\n";
			   map += "M M M M M                                                 >\n";
			   map += "M M M M M         T                     T                 >\n";
			   map += "M M M M                                            T     >\n";
			   map += "M M M     T               T                            >\n";
			   map += "M M M                                  T                >\n";
			   map += "M M M M         T                                     >\n";
			   map += "M M M M M M M M M M M M M M M M M M M M M M M M M M M M M M\n";
		return map;
	}

	static string Map_2_2()
	{
		string map  = "  ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ M\n";
			   map += "<                                                         M\n";
			   map += "<                                                         M\n";
			   map += "<                                                         M\n";
			   map += "<                                                         M\n";
			   map += "<                                                         M\n";
			   map += "<   # # #                                         # # #   M\n";
			   map += "<   #   # # # # # # # # # # ¿ ¿ # # # # # # # # # #   #   M\n";
			   map += "<   # # #                                         # # #   M\n";
			   map += "<     #                                             #     M\n";
			   map += "<     #                                             #     M\n";
			   map += "<     #   # # # # # # # # # ? ? # # # # # # # # #   #     M\n";
			   map += "<     #   #                                     #   #     M\n";
			   map += "<     #   #                                     #   #     M\n";
			   map += "<     #   #                                     #   #     M\n";
			   map += "<     #   #                                     #   #     M\n";
			   map += "<     #   #                                     #   #     M\n";
			   map += "<     #   #                                     #   ?     M\n";
			   map += "<     # # # # # # # # # # # * * # # # # # # # # # # #     M\n";
			   map += "M M M M M M M M M M M M M M M M M M M M M M M M M M M M M M\n";
		return map;
	}

};