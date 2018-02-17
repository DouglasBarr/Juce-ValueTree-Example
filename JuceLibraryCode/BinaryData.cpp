/* ==================================== JUCER_BINARY_RESOURCE ====================================

   This is an auto-generated file: Any edits you make may be overwritten!

*/

namespace BinaryData
{

//================== demo data.xml ==================
static const unsigned char temp_binary_data_0[] =
"<COLOURS>\r\n"
"    <COLOUR ColourId=\"01\" ColourName=\"Alizarin\"     ColourCode=\"0xffe74c3c\"/>\r\n"
"    <COLOUR ColourId=\"02\" ColourName=\"Carrot\"       ColourCode=\"0xffe67e22\"/>\r\n"
"    <COLOUR ColourId=\"03\" ColourName=\"Peterriver\"   ColourCode=\"0xff3498db\"/>\r\n"
"    <COLOUR ColourId=\"04\" ColourName=\"Emerland\"     ColourCode=\"0xff2ecc71\"/>\r\n"
"</COLOURS>\r\n";

const char* demo_data_xml = (const char*) temp_binary_data_0;


const char* getNamedResource (const char*, int&) throw();
const char* getNamedResource (const char* resourceNameUTF8, int& numBytes) throw()
{
    unsigned int hash = 0;
    if (resourceNameUTF8 != 0)
        while (*resourceNameUTF8 != 0)
            hash = 31 * hash + (unsigned int) *resourceNameUTF8++;

    switch (hash)
    {
        case 0xf58a2cde:  numBytes = 339; return demo_data_xml;
        default: break;
    }

    numBytes = 0;
    return 0;
}

const char* namedResourceList[] =
{
    "demo_data_xml"
};

}
