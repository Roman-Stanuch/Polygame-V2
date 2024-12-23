#include "resource_manager.h"
#include "stb/stb_image.h"
#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include <iostream>
#include <unordered_map>
#include <string>

static std::unordered_map<const char*, uint32_t> TextureMap;
static char* path_to_assets = "../../../../app/assets/";

namespace Polygame {
	namespace Resource {
		uint32_t GetTexture(const char* name, const char* path) {
			// Return the texture if already loaded
			if (TextureMap.find(name) != TextureMap.end())
				return TextureMap[name];

			// Return empty texture if requested (0 means identical)
			if (strcmp("color", name) == 0)
				return 0;

			// Else, load the texture and put it in TextureMap
			uint32_t textureID;
			glGenTextures(1, &textureID);
			glBindTexture(GL_TEXTURE_2D, textureID);

			int width, height, nrChannels;
			char final_path [100];
			sprintf(final_path, "%s%s", path_to_assets, path);
			unsigned char* data = stbi_load(final_path, &width, &height, &nrChannels, 0);
			if (data)
			{
				GLenum format;
				if (nrChannels == 1)
					format = GL_RED;
				else if (nrChannels == 3)
					format = GL_RGB;
				else if (nrChannels == 4)
					format = GL_RGBA;
				else
				{
					std::cout << "No valid image format found!" << std::endl;
					return 0;
				}

				glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
				glGenerateMipmap(GL_TEXTURE_2D);
			}
			else
			{
				const char* failureReason = stbi_failure_reason();
				std::cout << "Failed to load image: " << failureReason << std::endl;
				delete failureReason;
			}
			stbi_image_free(data);
			glBindTexture(GL_TEXTURE_2D, 0);

			TextureMap[name] = textureID;
			return textureID;

			return 0;
		}

		void SetAssetFolderPath(const char* path)
		{
			*path_to_assets = *path;
		}
	}
}