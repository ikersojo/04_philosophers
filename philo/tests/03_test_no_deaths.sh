# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    03_test_no_deaths.sh                               :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: isojo-go <isojo-go@student.42urduliz.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/05 15:50:10 by isojo-go          #+#    #+#              #
#    Updated: 2023/01/07 09:14:49 by isojo-go         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#! bin/zsh
echo "\033[0;93m    ---------- EAT 10 TIMES AND SURVIVE ----------\033[0;39m"

echo "\033[0;94m../bin/philo 5 800 200 200 10\033[0;39m"
../bin/philo 5 800 200 200 10
echo "\033[0;94m../bin/philo 5 800 200 200 10\033[0;39m"
echo "\033[0;96mNo philo should have died.OK? Press a key to continue\033[0;39m"
read ans

echo "\033[0;94m../bin/philo 4 410 200 200 10\033[0;39m"
../bin/philo 4 410 200 200 10
echo "\033[0;94m../bin/philo 4 410 200 200 10\033[0;39m"
echo "\033[0;96mNo philo should have died.OK? Press a key to continue\033[0;39m"
read ans

echo "\033[0;94m../bin/philo 200 5000 200 200 10\033[0;39m"
../bin/philo 200 5000 200 200 10
echo "\033[0;94m../bin/philo 4 410 200 200 10\033[0;39m"
echo "\033[0;96mNo philo should have died.OK? Press a key to continue\033[0;39m"
read ans

echo "\033[0;94m../bin/philo 199 5000 200 200 10\033[0;39m"
../bin/philo 199 5000 200 200 10
echo "\033[0;94m../bin/philo 199 5000 200 200 10\033[0;39m"
echo "\033[0;96mNo philo should have died.OK? Press a key to continue\033[0;39m"
read ans

echo "\033[0;94m../bin/philo 200 5000 0 200 10\033[0;39m"
../bin/philo 200 5000 0 200 10
echo "\033[0;94m../bin/philo 200 5000 0 200 10\033[0;39m"
echo "\033[0;96mNo philo should have died.OK? Press a key to continue\033[0;39m"
read ans

echo "\033[0;94m../bin/philo 199 5000 0 200 10\033[0;39m"
../bin/philo 199 5000 0 200 10
echo "\033[0;94m../bin/philo 199 5000 0 200 10\033[0;39m"
echo "\033[0;96mNo philo should have died.OK? Press a key to continue\033[0;39m"
read ans

echo "\033[0;94m../bin/philo 200 5000 200 0 10\033[0;39m"
../bin/philo 200 5000 200 0 10
echo "\033[0;94m../bin/philo 200 5000 200 0 10\033[0;39m"
echo "\033[0;96mNo philo should have died.OK? Press a key to continue\033[0;39m"
read ans

echo "\033[0;94m../bin/philo 199 5000 200 0 10\033[0;39m"
../bin/philo 199 5000 200 0 10
echo "\033[0;94m../bin/philo 199 5000 200 0 10\033[0;39m"
echo "\033[0;96mNo philo should have died.OK? Press a key to continue\033[0;39m"
read ans

echo "\033[0;94m../bin/philo 200 5000 0 0 10\033[0;39m"
../bin/philo 200 5000 0 0 10
echo "\033[0;94m../bin/philo 200 5000 0 0 10\033[0;39m"
echo "\033[0;96mNo philo should have died.OK? Press a key to continue\033[0;39m"
read ans

echo "\033[0;94m../bin/philo 199 5000 0 0 10\033[0;39m"
../bin/philo 199 5000 0 0 10
echo "\033[0;94m../bin/philo 199 5000 0 0 10\033[0;39m"
echo "\033[0;96mNo philo should have died.OK? Press a key to continue\033[0;39m"
read ans

echo "\033[0;94m../bin/philo 200 410 200 200 10\033[0;39m"
../bin/philo 200 410 200 200 10
# note that depending on the HW, 10 ms might not be enough to launch all threads
echo "\033[0;94m../bin/philo 200 410 200 200 10\033[0;39m"
echo "\033[0;96mNo philo should have died.OK? Press a key to continue\033[0;39m"
read ans

echo "\033[0;92mAll tests completed!"