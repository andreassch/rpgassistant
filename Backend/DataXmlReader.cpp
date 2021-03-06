#include "DataXmlReader.h"

DataXmlReader::DataXmlReader()
{
}

bool DataXmlReader::read(QIODevice* device)
{
    m_xml_reader.setDevice(device);

    if (m_xml_reader.readNextStartElement()) {
        if (m_xml_reader.name() == dataName()) {
            while (m_xml_reader.readNextStartElement()) {
                if (m_xml_reader.name() == entryName()) {
                    readEntry();
                }
                else {
                    m_xml_reader.skipCurrentElement();
                }
            }
        } else {
            m_xml_reader.raiseError(QObject::tr("The file is not a valid XML data file."));
        }
    }

    return !m_xml_reader.error();
}

QString DataXmlReader::errorString() const
{
    return QObject::tr("%1\nLine %2, column %3")
             .arg(m_xml_reader.errorString())
             .arg(m_xml_reader.lineNumber())
             .arg(m_xml_reader.columnNumber());
}
