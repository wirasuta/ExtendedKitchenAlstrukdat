#include "draw.h"


void print_title()
{
    printf("%s                      :::::::::: ::::    :::  :::::::: ::::::::::: ::: ::::::::   \n", KGRN);
    printf("%s                      :+:        :+:+:   :+: :+:    :+:    :+:     :+ :+:    :+:  \n", KGRN);
    printf("%s                      +:+        :+:+:+  +:+ +:+           +:+        +:+         \n", KGRN);
    printf("%s                      +#++:++#   +#+ +:+ +#+ :#:           +#+        +#++:++#++  \n", KGRN);
    printf("%s                      +#+        +#+  +#+#+# +#+   +#+#    +#+               +#+  \n", KGRN);
    printf("%s                      #+#        #+#   #+#+# #+#    #+#    #+#        #+#    #+#  \n", KGRN);
    printf("%s                      ########## ###    ####  ######## ###########     ########   \n", KGRN);
    printf("\n");
    printf("%s:::    ::: ::::::::::: ::::::::::: ::::::::  :::    ::: :::::::::: ::::    :::       ::::::::       :::::::  \n",KYEL);
    printf("%s:+:   :+:      :+:         :+:    :+:    :+: :+:    :+: :+:        :+:+:   :+:      :+:    :+:     :+:   :+: \n",KYEL);
    printf("%s+:+  +:+       +:+         +:+    +:+        +:+    +:+ +:+        :+:+:+  +:+            +:+      +:+  :+:+ \n",KYEL);
    printf("%s+#++:++        +#+         +#+    +#+        +#++:++#++ +#++:++#   +#+ +:+ +#+          +#+        +#+ + +:+ \n",KYEL);
    printf("%s+#+  +#+       +#+         +#+    +#+        +#+    +#+ +#+        +#+  +#+#+#        +#+          +#+#  +#+ \n",KYEL);
    printf("%s#+#   #+#      #+#         #+#    #+#    #+# #+#    #+# #+#        #+#   #+#+#       #+#       #+# #+#   #+# \n",KYEL);
    printf("%s###    ### ###########     ###     ########  ###    ### ########## ###    ####      ########## ###  #######  %s\n",KYEL,KNRM);
}

void print_credits()
{
printf("                          %s ██████╗██████╗ ███████╗██████╗ ██╗████████╗███████╗\n",KBLU);
printf("                          %s██╔════╝██╔══██╗██╔════╝██╔══██╗██║╚══██╔══╝██╔════╝\n",KBLU);
printf("                          %s██║     ██████╔╝█████╗  ██║  ██║██║   ██║   ███████╗\n",KBLU);
printf("                          %s██║     ██╔══██╗██╔══╝  ██║  ██║██║   ██║   ╚════██║\n",KBLU);
printf("                          %s╚██████╗██║  ██║███████╗██████╔╝██║   ██║   ███████║\n",KBLU);
printf("                          %s ╚═════╝╚═╝  ╚═╝╚══════╝╚═════╝ ╚═╝   ╚═╝   ╚══════╝\n",KBLU);
printf("                          -------------------------------------------------------\n");
printf("                          %s           Ainun Fitryh Vianiryzki\n",KRED);
printf("                          \n");
printf("                          %s            I Pute Gede Wirasuta\n",KRED);
printf("                          \n");
printf("                          %s             Kintan Sekar Adinda\n",KRED);
printf("                          \n");
printf("                          %s            M. Rifky I Bariansyah\n",KRED);
printf("                          \n");
printf("                          %s              Pandyaka Aptanagi\n",KRED);
printf("                          \n");
printf("                          %s                Raihan Asyraf%s\n",KRED,KNRM);

}

void print_menu()
{
  printf("                                            (1) New Game\n");
  printf("                                            (2) Start Game\n");
  printf("                                            (3) Load Game\n");
  printf("                                            (4) Exit\n\n");
  printf("                                      Please Input Your Choice : ");
}
