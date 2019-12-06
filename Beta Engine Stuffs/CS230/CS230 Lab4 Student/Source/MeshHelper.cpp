#include "stdafx.h"
#include "MeshHelper.h"

Beta::Mesh* CreateTriangleMesh(const Beta::Color& color0, const Beta::Color& color1, const Beta::Color& color2)
{
	using namespace Beta;

	//get access to the	meshfactory module
	MeshFactory& meshFactory = *EngineGetModule(MeshFactory);

	//make the vertex
	Vertex vertex0 = Vertex(Vector2D(-0.5f, 0.5f), color0);
	Vertex vertex1 = Vertex(Vector2D(-0.5f, -0.5f), color1);
	Vertex vertex2 = Vertex(Vector2D(0.5f, 0.0f), color2);

	//make the triangle with the vertexes above
	meshFactory.AddTriangle(vertex0, vertex1, vertex2);

	//save the mesh (list of triangles) in the mesh pointer
	Mesh* mesh = meshFactory.EndCreate();
	if (mesh == nullptr)
	{
		std::cout << "Failed to create mesh!" << std::endl;
	}

	return mesh;
}

Beta::Mesh* CreateQuadMesh(const Beta::Vector2D& uvSize, const Beta::Vector2D& meshSize)
{
	// Get access to the MeshFactorymodule
	using namespace Beta;
	MeshFactory& meshFactory = *EngineGetModule(MeshFactory);

	Vertex topLeft =     Vertex(Vector2D(-meshSize.x,  meshSize.y), Vector2D( 0.0f    ,  0.0f));
	Vertex bottomLeft =  Vertex(Vector2D(-meshSize.x, -meshSize.y), Vector2D( 0.0f    ,  uvSize.y));
	Vertex topRight =    Vertex(Vector2D( meshSize.x,  meshSize.y), Vector2D( uvSize.x,  0.0f));
	Vertex bottomRight = Vertex(Vector2D( meshSize.x, -meshSize.y), Vector2D( uvSize.x,  uvSize.y));

	meshFactory.AddTriangle(topLeft, bottomLeft, bottomRight);
	meshFactory.AddTriangle(topLeft, topRight, bottomRight);

	Mesh* mesh = meshFactory.EndCreate();
	if (mesh == nullptr)
	{
		std::cout << "Failed to create mesh!" << std::endl;
	}

	return mesh;
}
