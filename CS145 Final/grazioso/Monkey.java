/*
 * Method name: Monkey.java
 * 
 * A monkey class that keeps track of the money's information. Based on Dog.java class.
 * 
 * Author: Alexandria Scott
 * Creation Date: 10/4/2025
 * 
 * Revisions: 10/4/2025 by Alexandria Scott - Inherits from the RescueAnimal class
 *                                          - Created monkey specific attributes
 *                                          - Created mutator and accessor methods for each attribute
 */
public class Monkey extends RescueAnimal {

    // Instance variable 
    private String tailLength;
    private String height;
    private String bodyLength;
    private String species;

    // Constructor
    public Monkey (String name, String gender, String age,
    String weight, String acquisitionDate, String acquisitionCountry,
	String trainingStatus, boolean reserved, String inServiceCountry,
    String tailLength, String height, String bodyLength, String species) {
        // General traits
        setName(name);
        setGender(gender);
        setAge(age);
        setWeight(weight);
        setAcquisitionDate(acquisitionDate);
        setAcquisitionLocation(acquisitionCountry);
        setTrainingStatus(trainingStatus);
        setReserved(reserved);
        setInServiceCountry(inServiceCountry);
		setAnimalType("monkey"); // This line ensures animalType is set.

        // Monkey Specific traits
        setTailLength(tailLength);
        setHeight(height);
        setBodyLength(bodyLength);
        setSpecies(species);

    }

    // Accessor Methods
    public String getTailLength() {
        return tailLength;
    }

    public String getHeight() {
        return height;
    }

    public String getBodyLenth() {
        return bodyLength;
    }

    public String getSpecies() {
        return species;
    }

    // Mutator Methods
    public void setTailLength(String newTailLength) {
        tailLength = newTailLength;
    }

    public void setHeight(String newHeight) {
        height = newHeight;
    }

    public void setBodyLength(String newBodyLength) {
        bodyLength = newBodyLength;
    }

    public void setSpecies(String newSpecies) {
        species = newSpecies;
    }
}