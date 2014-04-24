/*! \brief This file is for doxygen main page.
    \file MainPage.h
    \author Alvaro Denis Acosta Quesada <denisacostaq\@gmail.com>
    \date Thu Jan 9 14:28:58 CDT 2014

    \brief This file is part of doxygen documentation.
    \brief Thie file become from: CIAA_v1_0/Doc/MainPage.h

    \attention <h1><center>&copy; COPYRIGHT
    GNU GENERAL PUBLIC LICENSE Version 3, 29 June 2007</center></h1>

    \copyright

    <a class="el" href="http://proyecto-ciaa.com.ar">
      This file is part of CIAA Project.
      ==================================
    </a>

    Copyright (C) 2014 $(Entidad que patenta)

    This software is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along
    with this program; if not, write to the Free Software Foundation, Inc.,
    51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */


/*! \mainpage CIAA Source documentation.
\image html fetch_005.png
\n Este documento presenta una propuesta para el desarrollo de una Computadora Industrial
Abierta Argentina, que consiste en una plaqueta electrónica provista de un microcontrolador y
puertos de entrada y salida, cuyo diseño estará disponible gratuitamente en internet, será
soportado por la comunidad de desarrolladores de la ACSE y, por su concepción, será apto
para su uso en procesos productivos y en sistemas de alta demanda.

De este modo la disponibilidad de este diseño será beneficiosa para distintos sectores:
- Pequeñas y medianas empresas: plataforma base para el desarrollo de sus productos.
- Universidades, terciarios y secundarios: soporte para la realización de clases prácticas.

Es importante destacar que se pretende desarrollar esta plataforma con recursos propios, a
través de una articulación entre actores privados, procurando no solicitar aportes al Estado

En [<strong>presente documento</strong>][este documento] se establecen los objetivos de la propuesta, los lineamientos de trabajo, el
rol de los diferentes actores, la organización de cada una de las etapas y el resultado esperado.
Se indican los requerimientos técnicos, la estimación de recursos necesarios, los criterios de
factibilidad económica, el plan para la fabricación de los primeros prototipos y los mecanismos
para lograr una apropiación colectiva de este desarrollo tecnológico nacional.

[este documento]: http://www.sase.com.ar/asociacion-civil-sistemas-embebidos/files/2013/11/Propuesta-Computadora-Industrial-Abierta-Argentina-ACSE-CADIEEL-v2.5.pdf "Propuesta Computadora Industrial Abierta Argentina. ACSE, CADIEEL"

<h1>Index:</h1>

- \subpage history "Historia"
- \subpage about "Acerca de"
- \subpage license "Lisencia"
- \subpage source_code "Descargar código fuente"
- \subpage contribution "¿Cómo contribuir?"
*/

//-----------------------------------------------------------

    /*! \page history <center>BREVE HISTORIA DE LA PRESENTE PROPUESTA</center>

  Esta propuesta se inscribe en una serie de mesas de diálogo convocadas por los Ministerios de
  Industria y de Ciencia, Tecnología e Innovación Productiva, en el marco del Plan Estratégico
  Industrial 2020, donde en la Mesa de Informática se identificó al Software Embebido como un
  eje transversal clave para diferentes cadenas de valor. Se convocó entonces a la Secretaría de
  Políticas Universitarias (SPU) del Ministerio de Educación, a la Cámara Argentina de Industrias
  Electrónicas, Electromecánicas y Luminotécnicas (CADIEEL), a la Cámara de Empresas del
  Software y Sistemas Informáticos (CESSI), y a otras cámaras relacionadas para analizar posibles
  medidas para promover el desarrollo del Software Embebido. En este contexto la SPU invitó al
  diálogo al Consejo Federal de Decanos de Ingeniería (CONFEDI), quién a su vez propuso la
  participación de la Asociación Civil para la Investigación, Promoción y Desarrollo de los
  Sistemas Embebidos (ACSE). Se organizó entonces una reunión en el Ministerio de Industria el
  17 de julio de 2013, dónde se presentaron los antecedentes de la ACSE y se explicó que en ella
  participan profesores de casi 50 facultades de ingeniería de todo el país. Además, ese día se
  discutieron varias iniciativas y se estableció que era importante hacer referencia a los
  “sistemas embebidos”, en lugar de hablar de software embebido, ya que la inquietud de los
  ministerios estaba orientada a la generación de valor agregado no sólo a través del desarrollo
  de software, sino también a partir del diseño y la fabricación nacional de los equipos
  electrónicos (“hardware”) que ejecutan dicho software.\n

  En las semanas siguientes se hicieron algunas reuniones preparatorias, y el 15 de agosto de
  2013, en el marco del Simposio Argentino de Sistemas Embebidos, SASE2013, organizado por
  la ACSE, tuvo lugar una reunión de trabajo en la cual participaron funcionarios de los citados
  Ministerios, representantes de CADIEEL, de la ACSE y de varias empresas(1). En esa reunión se
  analizó el impacto de diversos factores sobre el desarrollo de la industria electrónica nacional:


  - Herramientas de financiamiento estatal: las empresas manifestaron que si bien en
  algunos casos sería conveniente perfeccionar algunos mecanismos públicos de
  financiamiento, consideraban que si existe una oportunidad de negocio, entonces los
  fondos necesarios aparecen a través de recursos propios o de fuentes privadas.

  - Importación de componentes y piezas: las empresas comentaron que en muchos casos
  sería recomendable realizar ajustes en los mecanismos aduaneros para la importación
  de componentes electrónicos que luego serán utilizados en cadenas de valor, pero a la
  vez expresaron que si existe demanda para sus productos entonces siempre
  encuentran el modo de adaptarse a los procedimientos aduaneros establecidos.

  - Capacitación y recursos humanos: las empresas expresaron que sería conveniente que
  los jóvenes profesionales contaran con una mejor formación, pero que por lo general
  esto lo solucionan a partir de cursos y entrenamientos internos.

  En definitiva, se observó que aunque hay condiciones a revisar en relación con apoyos
  financieros, régimen aduanero y formación de recursos humanos, para las empresas la mayor
  preocupación está referida a encontrar negocios y mercados.

  A su vez, se planteó que la dificultad para encontrar negocios y mercados se debe
  principalmente a que en muchas ramas industriales existe un virtual desconocimiento respecto
  a la mejora en la competitividad y la rentabilidad que puede obtenerse a partir de la
  integración de sistemas electrónicos en productos, servicios y procesos productivos, y esta
  falta de información ocasiona que la oferta y la demanda queden desvinculadas, dificultando el
  crecimiento de la industria y la generación de valor agregado a partir de la articulación entre
  empresas complementarias.

  Se observó además que en nuestro país, aún en los casos en que se integran sistemas
  electrónicos en productos, servicios y procesos productivos, estos tienen un fuerte
  componente de partes importadas, si no es que se trata de sistemas diseñados y fabricados
  completamente en el exterior, como ocurre con los Controladores Lógicos Programables (PLC),
  que son la pieza clave para la automatización de líneas de montaje y producción de bienes de
  capital, bienes intermedios y de consumo. Se dijo que sería conveniente revertir esta situación.

  También se observó que muchas pequeñas y medianas empresas argentinas cuentan
  solamente con unas pocas personas con conocimientos básicos de electrónica, y a la vez
  fabrican productos que se encuentran en la etapa final de su ciclo de vida, por estar basados
  en tecnologías antiguas que en el mundo ya han sido dejadas de lado por ser más costosas y
  ofrecer menores prestaciones que las tecnologías más modernas, pero a estas empresas les
  resulta muy difícil afrontar el riesgo económico y el desafío tecnológico de modernizar los
  sistemas electrónicos que utilizan, y por lo tanto su supervivencia queda ligada a la
  preservación de nichos de mercado muy específicos o la fidelidad de sus clientes.

  En este contexto algunas empresas presentes en la reunión propusieron desarrollar un PLC
  argentino o algún producto similar que contribuyera a sustituir importaciones, a generar valor
  agregado y a fomentar la demanda de electrónica nacional. Esta propuesta se tomó para ser
  analizada en la ACSE, finalizando de ese modo el encuentro.

  Durante los días subsiguientes los firmantes de la primera versión de este documento
  concluyeron que desarrollar un PLC argentino en los términos habituales en que se aborda el
  desarrollo de un nuevo producto por parte de una empresa privada implicaría dos problemas:

  - Primero, se trataría de un producto que a nivel mundial está muy instituido, lo que
  implicaría competir en calidad con los productos establecidos que se elaboran en los
  países centrales, y competir en precio con los productos económicos que se elaboran
  en los países de oriente. Ambas cosas requieren de un capital inicial y de un tamaño de
  mercado que implican una fuerte barrera de ingreso.

  - Segundo, una solución desarrollada en esos términos implicaría un beneficio que
  estaría concentrado en unas pocas empresas: aquellas que fabricasen y comercialicen
  el PLC argentino. De modo que para fortalecer el crecimiento completo del sector
  electrónico luego sería necesario buscar tantas soluciones y propuestas como
  empresas hubiera, lo que naturalmente no es viable ni razonable.

  Por lo tanto, considerando las conclusiones de la reunión del 15 de agosto, se propuso el
  desarrollo de una Computadora Industrial Abierta Argentina (CIAA), que en usos y aplicaciones
  fuera similar a un PLC y pueda ser utilizada para sistemas de control de procesos productivos,
  agroindustria, automatización, etc., pero dónde lo diferente y atractivo de esta propuesta sería
  que al tratarse de una solución abierta toda la información de la plataforma estaría libremente
  disponible para cualquier empresa que estuviera interesada en utilizarla para elaborar sus
  propios productos y servicios, fomentando así el diseño y la fabricación nacional de sistemas
  electrónicos. Esto permitiría generar valor agregado y a su vez enriquecer la oferta local de
  soluciones vinculadas con esta plataforma, así como también alentar a que las instituciones
  educativas soporten a la industria mediante cursos de capacitación y servicios de consultoría.
  Además, al estar conformada la ACSE por profesores que tienen a su cargo el dictado de
  materias del área digital de casi 50 facultades de ingeniería de todo el país, y al contar esta
  iniciativa con el apoyo de la Secretaria de Políticas Universitarias del Ministerio de Educación,
  es esperable que las instituciones educativas universitarias, terciarias y secundarias adopten
  rápidamente esta plataforma para la formación de sus estudiantes, de modo que la inserción
  laboral de los jóvenes profesionales sea mucho más rápida y directa, a la vez que en la
  enseñanza de estas tecnologías se utilicen sistemas diseñados y fabricados en el país, y no en
  el exterior, como ocurre en la actualidad. Esto a su vez permitiría que las pequeñas y medianas
  empresas puedan actualizar la tecnología electrónica que emplean en sus productos, servicios
  y procesos productivos, teniendo la certeza de que contarán con recursos humanos
  capacitados y amplio soporte en el medio local. A su vez, la ACSE cuenta con casi dos mil
  miembros bien articulados mediante listas de correos y simposios anuales, lo que en términos
  del análisis FODA resulta en una Fortaleza y una Oportunidad respecto a otras economías
  emergentes, que no cuentan con este grado de articulación. De este modo las pequeñas y
  medianas empresas podrán aprovechar las soluciones abiertas que se vayan generando en
  esta comunidad, de modo que sus costos de desarrollo serán bajos, y los desafíos tecnológicos
  a afrontar estarán al alcance de sus posibilidades.

  Para que esta propuesta sea exitosa es necesario que desde su primera versión la CIAA sea una
  plataforma con buen desempeño y con un costo competitivo. A la vez se deben establecer
  reglas claras para su uso en productos y servicios por parte de las empresas, de modo de evitar
  controversias. También es necesario organizar la oferta de soluciones basadas en esta
  plataforma, de modo que las empresas sepan que si desarrollan un sistema atractivo entonces
  podrán acceder rápidamente a una gran cantidad de clientes interesados. En el mismo sentido,
  se debe lograr que las empresas productoras de bienes y servicios que demandan soluciones
  electrónicas conozcan esta plataforma y sepan dónde encontrar a las empresas que pueden
  proveerlas de soluciones basadas en ella. Esto implica crear un sistema de vinculación entre la
  oferta y la demanda, que requiere de recursos para sostenerse en el tiempo. Pero estos
  recursos no son significativos respecto al volumen total de negocios que se espera generar, y
  podrían obtenerse a partir de contribuciones de las propias empresas beneficiadas, cuyos
  aportes podrían además utilizarse para hacer mejoras continuas en esta plataforma abierta.

  Esta propuesta fue presentada en reuniones posteriores con representantes de CADIEEL y de
  los Ministerios, logrando consenso y amplio apoyo, a la vez que incorporando ajustes y
  mejoras. De este modo, se fueron definiendo cada uno de los puntos del [<strong>presente documento</strong>][este documento],
  que se presenta a  continuación.

    [este documento]: http://www.sase.com.ar/asociacion-civil-sistemas-embebidos/files/2013/11/Propuesta-Computadora-Industrial-Abierta-Argentina-ACSE-CADIEEL-v2.5.pdf "Propuesta Computadora Industrial Abierta Argentina. ACSE, CADIEEL"

    */

//-----------------------------------------------------------

  /*! \page about <center>Acerca de la CIAA</center>

Los objetivos generales de la presente propuesta son los siguientes:
- Desarrollar una computadora industrial que sea aprovechada por las pequeñas y
medianas empresas para mejorar y modernizar sus productos y servicios, a fin de
fomentar el desarrollo tecnológico y económico de la industria electrónica nacional, y
de las cadenas de valor asociadas.

- Procurar la apropiación colectiva de esta plataforma, para que a partir de ella se
desarrollen nuevos productos y servicios, y se logre vincular la oferta y la demanda de
soluciones electrónicas, de modo que sea posible sustituir importaciones, mejorar la
competitividad de distintas ramas industriales y aumentar su valor agregado.

- Fomentar que las universidades, terciarios y escuelas técnicas de todo el país utilicen
esta plataforma en la formación de recursos humanos, de modo facilitar la inserción
laboral de los jóvenes profesionales y dar soporte a las actuales iniciativas que buscan
articular a las instituciones educativas con los sectores productivos.


website: http://www.sase.com.ar/asociacion-civil-sistemas-embebidos/ciaa/

  */

//-----------------------------------------------------------

/*! \page license <center>Copyright&copy; The Regents of the University of California.</center>
Copyright&copy; The Regents of the University of California.
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions
are met:
1. Redistributions of source code must retain the above copyright
   notice, this list of conditions and the following disclaimer.
2. Redistributions in binary form must reproduce the above copyright
   notice, this list of conditions and the following disclaimer in the
   documentation and/or other materials provided with the distribution.
3. Neither the name of the University nor the names of its contributors
   may be used to endorse or promote products derived from this software
   without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
SUCH DAMAGE.
*/


//-----------------------------------------------------------

/*! \page source_code Descargar código fuente.
- Stable version:\n
    - NULL
- Last code:\n
    - https://github.com/ciaa/CIAA_v1_0.git
*/

//-----------------------------------------------------------

/*! \page contribution ¿Cómo contribuir?.
- Fork our repository on github, commit your changes, and send a "pull request" to us.
We will merge your contribution to master.
- Any suggestion, bug fix, improvment will be appreciated.
*/
