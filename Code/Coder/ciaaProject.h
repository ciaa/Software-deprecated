#ifndef CIAAPROJECT_H
#define CIAAPROJECT_H

#include "IEC61131Standard/Projects/ciaaIECProject.h"
#include "IL/Visualiser/ciaaVIL_Controller.h"
#include "Ladder/Visualiser/ciaaVLadder_Controller.h"

/*! \brief ciaaProject is the class that has the all the information used by a project.
 *  \brief The class has the project in terms ot IEC61131 standard, in terms of instruction list language and in terms of ladder language.
 *  \brief Allows converrtions from instructon list language to ladder language.
 *  \ingroup Coder
 */

class ciaaProject
{
    public:
        ciaaProject();

    private:
        DISALLOW_COPY_AND_ASSIGN(ciaaProject);

        /*! \brief variable that has the project in terms of IEC61131 standard */
        ciaaIECProject* pIECProject;

        /*! \brief variable that has the project in terms of instruction list language */
        ciaaVIL_Controller* pILProject;

        /*! \brief variable that has the project in terms of ladder language */
        ciaaVLadder_Controller* pLadderProject;
};

#endif // CIAAPROJECT_H
