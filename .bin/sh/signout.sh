#!/bin/bash

#automatically sign out of all git repos
submodules=$(git submodule | awk '{print $2}')

#specify the path of the submodules you wish to not push
avoid_submodules=("minishell")

#if alias for signout doesen't exist, create it
if alias 'byebye' >/dev/null 2>&1; then
	alias byebye="pipenv run bye";
fi

clear
echo "Signing out..."

function current_branch(){
	git rev-parse --abbrev-ref HEAD
}

function add_commit_push(){
	git add --all > /dev/null 2>&1
	git commit -m "See you space cowboy." > /dev/null 2>&1
	git push origin $(current_branch) > /dev/null 2>&1
}

for submodule in $submodules; do
	if ! [[ " ${avoid_submodules[*]} " == *" ${submodule} "* ]]; then
		cd $submodule
		add_commit_push
		cd ..
	fi
done

add_commit_push

echo "                                                .                                                   "
echo "                                                                                             x      "
echo "                 .                                                                                  "
echo "                                                                      .                             "
echo "                                                                                                    "
echo "        x                                                                                PG         "
echo "                              +                    G55                                   PP         "
echo "                      +                             BYYG                                  P5        "
echo "                                                   BYY5                                  P5B        "
echo "                                                  55YG                          .        P5G        "
echo "                                                GPGPP5PPPPPBBPPGGGPGP5PB                 PP &       "
echo "                   +               .            BP55GPP5555555YJYPPPPGBBB                 PPPB      "
echo "                                               BBBBBGP5YYYYPBGPGBGPBBBBBBGBBBBB        BG55YY5B     "
echo "                                        BBBGGGBBGP55555YYY55GGPPPPP555555555555555PP555YYJ?7!J5G    "
echo "                                      BGGBGGGBBGGGGBBBBG5YYYYYYY5555PP555555PGBGGP5YJ?7!~~~~~!7JG   "
echo "      .                               BB BGGBBB  BBBBGBGGBPYYYYYY55PBGGGGGGGGPPBPPBBY~^~~~~~~7?JG   "
echo "                                    G5GGPPPPPPPPP5555PPPPP5Y55555555PGPPPPPPPPPPGBB Y77?!7?YPB &    "
echo "                             BBGPP555YYYYYYYYYYY5P555555555555555GPGGGGPPPPPPPPPPBBB PYPPGBB        "
echo "                    BBGPPP55555YYYYYYYY5YYYY55555555555PP5555555PB BGGGGGGGGGPPPGBB  B   GB         "
echo "                 GP5YY5555YYYY55555555555PPGGPPP5555P5P55555PPPGBBBBB  BBBGGGGBGPGB      PPB        "
echo "             BGPP5YY5YYYYYY555555555YY55GGP5G5555PPPPGPPPGGGGBB BBBB         BBGPG       P5B        "
echo "         BG5YYYY555555555YYYYYYY5GGGGGPBBBPPGPPPPPPPPGBGG  BB  BGB                       PP         "
echo "      GP5YYYYY55YPPYPY5P555PPPPPPGBBBGGBBBGPPPPGGGGGGGGG      BGB                        PG         "
echo "    G55J5PY5P55P5PPPPPPPPPPPPP5PGGBBGPGBBGGGGGGGGGBBB       BBB                          PG         "
echo "   GPPGPPPPPPPPPPPPPPPPPPPGGPPP5PGBGPGBBGGGGBGGBB         B                              PB         "
echo "       BBBBGGGGPPPPPPBGPGPPPPGBBGBGGGBBBBBBB                                                        "
echo "              BBBBBBBBBBBBBBBBBBBBBBBBB                                                             "
echo "                                                                                    x               "
echo "     +                                                                                              "
echo "                                                                 .                                  "
echo "                                                             +                                      "
echo "                                 x                                                                  "
echo "            x                                                                                       "
echo "                                                                     See you space cowboy.          "
echo "                                                                                                    "

exit 0
