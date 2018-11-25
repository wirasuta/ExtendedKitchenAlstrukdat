#include <stdio.h>
#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"


void print_title()
{
    printf("%s                      :::::::::: ::::    :::  :::::::: ::::::::::: ::: ::::::::   \n", KGRN);
    printf("%s                      :+:        :+:+:   :+: :+:    :+:    :+:     :+ :+:    :+:  \n", KGRN);
    printf("%s                      +:+        :+:+:+  +:+ +:+           +:+        +:+         \n", KGRN);
    printf("%s                      +#++:++#   +#+ +:+ +#+ :#:           +#+        +#++:++#++  \n", KGRN);
    printf("%s                      +#+        +#+  +#+#+# +#+   +#+#    +#+               +#+  \n", KGRN);
    printf("%s                      #+#        #+#   #+#+# #+#    #+#    #+#        #+#    #+#  \n", KGRN);
    printf("%s                      ########## ###    ####  ######## ###########     ########   \n", KGRN);
    printf("\n");printf("\n");
    printf("%s:::    ::: ::::::::::: ::::::::::: ::::::::  :::    ::: :::::::::: ::::    :::       ::::::::       :::::::  \n",KYEL);
    printf("%s:+:   :+:      :+:         :+:    :+:    :+: :+:    :+: :+:        :+:+:   :+:      :+:    :+:     :+:   :+: \n",KYEL);
    printf("%s+:+  +:+       +:+         +:+    +:+        +:+    +:+ +:+        :+:+:+  +:+            +:+      +:+  :+:+ \n",KYEL);
    printf("%s+#++:++        +#+         +#+    +#+        +#++:++#++ +#++:++#   +#+ +:+ +#+          +#+        +#+ + +:+ \n",KYEL);
    printf("%s+#+  +#+       +#+         +#+    +#+        +#+    +#+ +#+        +#+  +#+#+#        +#+          +#+#  +#+ \n",KYEL);
    printf("%s#+#   #+#      #+#         #+#    #+#    #+# #+#    #+# #+#        #+#   #+#+#       #+#       #+# #+#   #+# \n",KYEL);
    printf("%s###    ### ###########     ###     ########  ###    ### ########## ###    ####      ########## ###  #######  \n",KYEL);
}

void print_credits()
{
printf("%s ██████╗██████╗ ███████╗██████╗ ██╗████████╗███████╗\n",KBLU);
printf("%s██╔════╝██╔══██╗██╔════╝██╔══██╗██║╚══██╔══╝██╔════╝\n",KBLU);
printf("%s██║     ██████╔╝█████╗  ██║  ██║██║   ██║   ███████╗\n",KBLU);
printf("%s██║     ██╔══██╗██╔══╝  ██║  ██║██║   ██║   ╚════██║\n",KBLU);
printf("%s╚██████╗██║  ██║███████╗██████╔╝██║   ██║   ███████║\n",KBLU);
printf("%s ╚═════╝╚═╝  ╚═╝╚══════╝╚═════╝ ╚═╝   ╚═╝   ╚══════╝\n",KBLU);
printf("-------------------------------------------------------\n");
printf("%s           Ainun Fitryh Vianiryzki\n",KRED);
printf("\n");
printf("%s            I Pute Gede Wirasuta\n",KRED);
printf("\n");
printf("%s             Kintan Sekar Adinda\n",KRED);
printf("\n");
printf("%s            M. Rifky I Bariansyah\n",KRED);
printf("\n");
printf("%s              Pandyaka Aptanagi\n",KRED);
printf("\n");
printf("%s                Raihan Asyraf\n",KRED);

}
int main()
{
  print_credits();
}
