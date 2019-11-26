package ia;

import java.io.File;
import java.io.FileNotFoundException;

import com.ibm.watson.developer_cloud.natural_language_classifier.v1.model.Classification;
import com.ibm.watson.developer_cloud.natural_language_classifier.v1.model.Classifier;
import com.ibm.watson.developer_cloud.natural_language_classifier.v1.model.ClassifierList;
import com.ibm.watson.developer_cloud.natural_language_classifier.v1.model.ClassifyOptions;
import com.ibm.watson.developer_cloud.natural_language_classifier.v1.model.CreateClassifierOptions;
import com.ibm.watson.developer_cloud.natural_language_classifier.v1.model.GetClassifierOptions;

import core.InterfaceIA;

public class IaWatson implements InterfaceIA{
	
	private String username;
	private String password;
	private String url;
	private NaturalLanguageClassifier service;
	
	public IaWatson() {
		username = "e88c4313-d9a2-445c-8246-29168c3ef6a6";
		password = "6QMUX5QdO6vm";
		url = "https://gateway.watsonplatform.net/natural-language-classifier/api";
		service = new NaturalLanguageClassifier(username,password);
	}
	
	@Override
	public String genererReponse(String question) {
		String classifierId = "";
		
		ClassifierList list = service.listClassifiers().execute();
		
		System.out.println(service.getEndPoint());
		System.out.println(service.getName());
		System.out.println(list.getClassifiers());
		System.out.println(service.getToken());
		
		
		
		classifierId = list.getClassifiers().get(0).getClassifierId();
		
		GetClassifierOptions getOptions = new GetClassifierOptions.Builder()
				  .classifierId(classifierId)
				  .build();
		System.out.println(service.getClassifier(getOptions).execute().getStatus());
		
		ClassifyOptions options = new ClassifyOptions.Builder()
				.classifierId(classifierId)
				.text(question)
				.build();
		Classification result = service.classify(options).execute();
		return result.getTopClass();
	}
	
	
	//renvoie l'id du classifier
	public String createAndTrain(NaturalLanguageClassifier service,String pathTrainingFile, String pathMetadataFile) throws FileNotFoundException{
		File trainingData = new File(pathTrainingFile);
		File metaData = new File(pathMetadataFile);
		CreateClassifierOptions options = new CreateClassifierOptions.Builder()
				.metadata(metaData)
				.trainingData(trainingData)
				.build();
		Classifier response = service.createClassifier(options).execute();
		return response.getClassifierId();
	}
	
}
