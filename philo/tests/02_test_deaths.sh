# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    02_test_deaths.sh                                  :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: isojo-go <isojo-go@student.42urduliz.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/05 15:45:10 by isojo-go          #+#    #+#              #
#    Updated: 2023/01/15 08:56:49 by isojo-go         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#! bin/zsh
echo "\033[0;93m    ---------- DEATHS ----------\033[0;39m"
echo "\033[0;94m../bin/philo 1 800 200 200\033[0;39m"
../bin/philo 1 800 200 200
echo "\033[0;96mThe philo should not eat and die. OK? Press enter to continue\033[0;39m"
read ans

echo "\033[0;94m../bin/philo 4 310 200 200\033[0;39m"
../bin/philo 4 310 200 200
echo "\033[0;96mA philo should die between 310ms and 320ms. OK? Press enter to continue\033[0;39m"
read ans

echo "\033[0;94m../bin/philo 200 100 200 200\033[0;39m"
../bin/philo 200 100 200 200
echo "\033[0;96mHas a philosopher die between 100ms and 110ms? Press enter to continue\033[0;39m"
read ans

echo "\033[0;94m../bin/philo 200 200 5000 200\033[0;39m"
../bin/philo 200 200 5000 200
echo "\033[0;96mHas a philosopher die between 200ms and 210ms? Press enter to continue\033[0;39m"
read ans

echo "\033[0;94m../bin/philo 200 800 200 5000\033[0;39m"
../bin/philo 200 800 200 5000
echo "\033[0;96mHas a philosopher die between 800ms and 810ms? Press enter to continue\033[0;39m"
read ans

echo "\033[0;94m../bin/philo 200 200 200 200\033[0;39m"
../bin/philo 200 200 200 200
echo "\033[0;96mHas a philosopher die between 200ms and 210ms? Press enter to continue\033[0;39m"
read ans

echo "\033[0;94m../bin/philo 199 410 200 200\033[0;39m"
../bin/philo 199 410 200 200
echo "\033[0;96mHas a philosopher die between 410ms and 420ms? Press enter to continue\033[0;39m"
read ans

echo "\033[0;92mAll tests completed!"