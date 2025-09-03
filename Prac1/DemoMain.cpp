#include "Canvas.h"
#include "Caretaker.h"
#include "ExportCanvas.h"
#include "Memento.h"
#include "PDFExporter.h"
#include "PNGExporter.h"
#include "Rectangle.h"
#include "RectangleFactory.h"
#include "Shape.h"
#include "ShapeFactory.h"
#include "Square.h"
#include "SquareFactory.h"
#include "Textbox.h"
#include "TextboxFactory.h"

int main()
{
    //                                                         SECTION 1:FACTORIES
    // =====================================================================================================================================================================
    std::cout << std::endl
              << "SECTION 1: FACTORIES" << std::endl;
    //******************************************************************************************************************************************************************* */

    std::cout << "SECTION 1.1: RECTANGLE FACTORY" << std::endl;

    std::cout << "Creating Rectangle Factory..." << std::endl;
    RectangleFactory *recFactory = new RectangleFactory();
    std::cout << "SUCCESS" << std::endl;

    std::cout << "Instantiating a rectangle using rectangle factory..." << std::endl;
    Shape *rec = recFactory->createShape();
    std::cout << "SUCCESS" << std::endl;

    std::cout << "Attempting clone..." << std::endl;
    Shape *rec_clone = rec->clone();
    std::cout << "SUCCESS" << std::endl
              << std::endl;

    //******************************************************************************************************************************************************************* */
    std::cout << "SECTION 1.2: SQUARE FACTORY" << std::endl;

    std::cout << "Creating Square Factory..." << std::endl;
    SquareFactory *squareFactory = new SquareFactory();
    std::cout << "SUCCESS" << std::endl;

    std::cout << "Instantiating a square using square factory..." << std::endl;
    Shape *square = squareFactory->createShape();
    std::cout << "SUCCESS" << std::endl;

    std::cout << "Attempting clone..." << std::endl;
    Shape *sqr_clone = square->clone();
    std::cout << "SUCCESS" << std::endl
              << std::endl;

    //******************************************************************************************************************************************************************* */
    std::cout << "SECTION 1.3: TEXTBOX FACTORY" << std::endl;

    std::cout << "Creating Textbox Factory..." << std::endl;
    TextboxFactory *txtboxFactory = new TextboxFactory();
    std::cout << "SUCCESS" << std::endl;

    std::cout << "Instantiating a textbox using textbox factory..." << std::endl;
    Shape *txt = txtboxFactory->createShape();
    std::cout << "SUCCESS" << std::endl;

    std::cout << "Attempting clone..." << std::endl;
    Shape *txt_clone = txt->clone();
    std::cout << "SUCCESS" << std::endl;

    std::cout << "SECTION 1: FACTORIES SUCCESSFUL" << std::endl
              << std::endl;

    //                                                              SECTION 2:CANVAS
    // =====================================================================================================================================================================
    std::cout << "SECTION 2: CANVAS" << std::endl;
    std::cout << "SECTION 2.1: CREATE CANVAS, ADD/STORE A GREEN RECTANGLE" << std::endl;

    std::cout << "Creating canvas..." << std::endl;
    Canvas *mspaint = new Canvas();
    std::cout << "SUCCESS" << std::endl;

    std::cout << "Testing Case: Empty prev/post..." << std::endl;
    mspaint->undoAction();
    std::cout << "Successful undo..." << std::endl;

    mspaint->redoAction();
    std::cout << "Successful redo..." << std::endl;
    std::cout << "SUCCESS" << std::endl;

    std::cout << "Changing colour of rectangle to green..." << std::endl;
    rec->changeColour("Green");
    std::cout << "SUCCESS" << std::endl;

    std::cout << "Changing width and length of rectangle..." << std::endl;
    rec->changeLength(6);
    rec->changeWidth(3);
    std::cout << "SUCCESS" << std::endl;

    std::cout << "Changing position of rectangle..." << std::endl;
    rec->changePosition(12, 23);
    std::cout << "SUCCESS" << std::endl;

    std::cout << "Adding rectangle to canvas..." << std::endl;
    mspaint->addToCanvas(rec);
    std::cout << "SUCCESS" << std::endl;

    std::cout << "Printing rectangle..." << std::endl;
    rec->toString();
    std::cout << "SUCCESS" << std::endl
              << std::endl;

    //******************************************************************************************************************************************************************* */
    std::cout << "SECTION 2.2: ADD/STORE A RED SQUARE" << std::endl;

    std::cout << "Changing colour of square to red..." << std::endl;
    square->changeColour("Red");
    std::cout << "SUCCESS" << std::endl;

    std::cout << "Changing width and length of square..." << std::endl;
    square->changeLength(9);
    square->changeWidth(9);
    std::cout << "SUCCESS" << std::endl;

    std::cout << "Changing position of square..." << std::endl;
    square->changePosition(11, 13);
    std::cout << "SUCCESS" << std::endl;

    std::cout << "Adding square to canvas..." << std::endl;
    mspaint->addToCanvas(square);
    std::cout << "SUCCESS" << std::endl;

    std::cout << "Printing square..." << std::endl;
    square->toString();
    std::cout << "SUCCESS" << std::endl
              << std::endl;

    //******************************************************************************************************************************************************************* */
    std::cout << "SECTION 2.3: ADD/STORE A WHITE TEXTBOX" << std::endl;

    std::cout << "Changing colour of textbox to white..." << std::endl;
    txt->changeColour("White");
    std::cout << "SUCCESS" << std::endl;

    std::cout << "Changing width and length of textbox..." << std::endl;
    txt->changeLength(10);
    txt->changeWidth(3);
    std::cout << "SUCCESS" << std::endl;

    std::cout << "Changing position of textbox..." << std::endl;
    txt->changePosition(11, 13);
    std::cout << "SUCCESS" << std::endl;

    std::cout << "Adding square to canvas..." << std::endl;
    mspaint->addToCanvas(square);
    std::cout << "SUCCESS" << std::endl;

    std::cout << "Setting text of textbox..." << std::endl;
    TextBox *txt_test = new TextBox();
    txt_test->changeColour("White");
    txt_test->setText("Hello World");
    txt_test->changePosition(11, 13);
    txt_test->changeLength(10);
    txt_test->changeWidth(3);

    std::cout << "Printing textbox..." << std::endl;
    txt_test->toString();
    std::cout << "SUCCESS" << std::endl
              << std::endl;

    //******************************************************************************************************************************************************************* */
    std::cout << "SECTION 2.4: UNDO" << std::endl;
    std::cout << "Performing an AddToCanvas() for undo test..." << std::endl;

    Shape *square_undo = square->clone();
    std::cout << "SUCCESS" << std::endl;

    std::cout << "Adding to canvas..." << std::endl;
    mspaint->addToCanvas(square_undo);
    std::cout << "SUCCESS" << std::endl;

    std::cout << "Attempting undo..." << std::endl;
    mspaint->undoAction();
    std::cout << "SUCCESS" << std::endl
              << std::endl;

    //******************************************************************************************************************************************************************* */
    std::cout << "SECTION 2.5: REDO" << std::endl;

    std::cout << "Attempting redo..." << std::endl;
    mspaint->redoAction();
    std::cout << "SUCCESS" << std::endl<<std::endl;

    //******************************************************************************************************************************************************************* */
    std::cout << "SECTION 2.6: ADDITIONAL TESTING" << std::endl;

    std::cout << "Performing additional tests..." << std::endl;
    Canvas *extra = new Canvas();
    extra->contains();
    extra->addShape("Rectangle");
    extra->changeColour("Green");
    extra->changeLength(3);
    extra->changeWidth(2);
    extra->changePosition(3, 3);
    extra->captureCurrent();
    extra->contains();
    extra->removeFromCanvas();
    delete extra;
    std::cout << "SUCCESS" << std::endl;

    std::cout << "SECTION 2: CANVAS SUCCESSFUL" << std::endl
              << std::endl;

    //                                                              SECTION 3:PDF/PNG
    // =====================================================================================================================================================================
    std::cout << "SECTION 3: PDF/PNG" << std::endl;
    std::cout << "SECTION 3.1: EXPORT TO PDF" << std::endl;
    std::cout << "Attempting to export to PDF..." << std::endl;
    mspaint->PDFCanvas();
    std::cout << "SUCCESS" << std::endl
              << std::endl;

    //******************************************************************************************************************************************************************* */
    std::cout << "SECTION 3.2: EXPORT TO PNG" << std::endl;
    std::cout << "Attempting to export to PNG..." << std::endl;
    mspaint->PNGCanvas();
    std::cout << "SUCCESS" << std::endl;

    std::cout << "SECTION 3: PDF/PNG SUCCESSFUL" << std::endl;
    // =====================================================================================================================================================================

    delete square;
    delete squareFactory;
    delete sqr_clone;

    delete rec;
    delete recFactory;
    delete rec_clone;

    delete txt;
    delete txt_clone;
    delete txtboxFactory;

    delete mspaint;
    return 0;
}
