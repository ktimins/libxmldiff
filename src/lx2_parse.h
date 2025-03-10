/* ****************************************************************************
 * lx2_parse.h : parsing xmldiff commands                                     *
 * -------------------------------------------------------------------------- *
 *                                                                            *
 * Copyright (C) 2004 - Rémi Peyronnet <remi+xmldiff@via.ecp.fr>              *
 *                                                                            *
 * This program is free software; you can redistribute it and/or              *
 * modify it under the terms of the GNU General Public License                *
 * as published by the Free Software Foundation; either version 2             *
 * of the License, or (at your option) any later version.                     *
 *                                                                            *
 * This program is distributed in the hope that it will be useful,            *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of             *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the              *
 * GNU General Public License for more details.                               *
 *                                                                            *
 * You should have received a copy of the GNU General Public License          *
 * along with this program; if not, write to the Free Software                *
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.*
 * http://www.gnu.org/copyleft/gpl.html                                       *
 * ************************************************************************** */

#ifndef __LIBXML2_PARSE_H__
#define __LIBXML2_PARSE_H__


#include "libxmldiff.h"
#include "lx2_ops.h"

/** parseOption : parse option item
 * @param option the option
 * @param arg the option argument (must be empty if none)
 * @param opt [in, out] the structure that contains the result options
 * @return the number of element taken :
 *          0 if an error has occured
 *          1 if only the option was taken
 *          2 if the argument was usefull
 */
int LIBXMLDIFF_API parseOption(const std::string & option, const std::string & arg, /* [in, out] */ struct globalOptions & opt);

/** parseAction : parse action item
 * @param action std::string containing the action
 * @param cmd command structure
 * @return 0 if no error happened
 * @note Set default values for actions
 */
int LIBXMLDIFF_API parseAction(std::string action, struct appCommand & cmd);

/** parseCommandLine : parse command line
 * @param cl arguments std::vector
 * @param opt [in, out] the structure that contains the result options
 * @return status code : 0 means no error
 */
int LIBXMLDIFF_API parseCommandLine(const std::vector<std::string> & cl, /* [in, out] */ struct appCommand & opt);

/// Execute an action from the command line
int LIBXMLDIFF_API executeAction(const struct appCommand & cmd);

/** tokenizeCommand : parse command line
 * @param command command std::string
 * @return the list of tokens
 */
std::vector<std::string> tokenizeCommand(std::string command);

/** Replace tokens by other values
 * @param tokens [in, out] the list of tokens
 * @param variables the list of variables name/value
 * @return the number of token replaced, or negative value on error
 */
int replaceTokens(std::vector<std::string> & /*[in, out]*/ tokens, std::map<std::string, std::string> variables);

/** Execute file
 * @param scriptFileName the filename of the script to execute
 * @param variables the variables passed to the script 
 * @param gOptions the global options of xmldiff
 * @return status code : 
 *        0 no problems
 *      -10 file not found
 */
int LIBXMLDIFF_API executeFile(std::string scriptFileName, const std::map<std::string, std::string> & variables, const struct globalOptions & gOptions);

/** Split a std::string into a std::vector */
void splitVector(const std::string arg, /*[in,out]*/ std::vector<xmlstring> & v);

/** Join a std::vector into a std::string */
std::string joinVector(const std::vector<xmlstring> & v);



/// Print usage
void LIBXMLDIFF_API usage();

/// Dump current configuration
void LIBXMLDIFF_API printConfiguration(const struct globalOptions & opt);

#endif // __LIBXML2_PARSE_H__
